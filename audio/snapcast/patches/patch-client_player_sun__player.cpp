$NetBSD: patch-client_player_sun__player.cpp,v 1.1 2022/07/03 16:09:15 nia Exp $

Add Sun Audio support for NetBSD.

--- client/player/sun_player.cpp.orig	2022-07-03 14:25:19.031712372 +0000
+++ client/player/sun_player.cpp
@@ -0,0 +1,305 @@
+/***
+    This file is part of snapcast
+    Copyright (C) 2014-2021  Johannes Pohl
+
+    This program is free software: you can redistribute it and/or modify
+    it under the terms of the GNU General Public License as published by
+    the Free Software Foundation, either version 3 of the License, or
+    (at your option) any later version.
+
+    This program is distributed in the hope that it will be useful,
+    but WITHOUT ANY WARRANTY; without even the implied warranty of
+    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+    GNU General Public License for more details.
+
+    You should have received a copy of the GNU General Public License
+    along with this program.  If not, see <http://www.gnu.org/licenses/>.
+***/
+
+#include <sys/audioio.h>
+#include <sys/ioctl.h>
+#include <fcntl.h>
+#include <unistd.h>
+#include "sun_player.hpp"
+#include "common/aixlog.hpp"
+#include "common/snap_exception.hpp"
+#include "common/str_compat.hpp"
+#include "common/utils/logging.hpp"
+#include "common/utils/string_utils.hpp"
+
+#ifndef SUN_MAXDEVS
+#define SUN_MAXDEVS (16)
+#endif
+
+#ifndef AUDIO_GETBUFINFO
+#define AUDIO_GETBUFINFO AUDIO_GETINFO
+#endif
+
+#ifndef AUDIO_ENCODING_SLIENAR
+#define AUDIO_ENCODING_SLIENAR AUDIO_ENCODING_LINEAR8;
+#endif
+
+#ifndef AUDIO_ENCODING_SLIENAR_LE
+#define AUDIO_ENCODING_SLIENAR_LE AUDIO_ENCODING_LINEAR;
+#endif
+
+using namespace std::chrono_literals;
+using namespace std;
+
+namespace player
+{
+
+static constexpr std::chrono::milliseconds BUFFER_TIME = 10ms;
+static constexpr int PERIODS = 3;
+static constexpr int MIN_PERIODS = 1;
+
+static constexpr auto LOG_TAG = "Sun";
+
+SunPlayer::SunPlayer(boost::asio::io_context& io_context, const ClientSettings::Player& settings, std::shared_ptr<Stream> stream)
+    : Player(io_context, settings, stream), handle_(-1)
+{
+}
+
+void SunPlayer::initSun()
+{
+    std::lock_guard<std::recursive_mutex> lock(mutex_);
+    const char *dev;
+    const SampleFormat& format = stream_->getFormat();
+    struct audio_info info;
+    uint32_t rate = format.rate();
+    int channels = format.channels();
+
+    // Open the PCM device in playback mode
+    if (settings_.pcm_device.name == "default")
+        dev = "/dev/audio";
+    else
+        dev = settings_.pcm_device.name.c_str();
+
+    if ((handle_ = open(dev, O_WRONLY)) < 0)
+        throw SnapException("Can't open " + settings_.pcm_device.name + ", error: " + strerror(errno));
+
+    AUDIO_INITINFO(&info);
+
+    switch (format.bits()) {
+    case 8:
+        info.play.encoding = AUDIO_ENCODING_SLINEAR;
+        info.play.precision = 8;
+        break;
+    case 16:
+        info.play.encoding = AUDIO_ENCODING_SLINEAR_LE;
+        info.play.precision = 16;
+        break;
+    case 32:
+        info.play.encoding = AUDIO_ENCODING_SLINEAR_LE;
+        info.play.precision = 32;
+        break;
+    default:
+        throw SnapException("Unsupported sample format: " + cpt::to_string(format.bits()));
+        break;
+    }
+
+    if (ioctl(handle_, AUDIO_SETINFO, &info) < 0)
+    {
+        throw SnapException("Unsupported sample format: " + cpt::to_string(format.bits()));
+    }
+
+    AUDIO_INITINFO(&info);
+
+    info.play.channels = channels;
+
+    if (ioctl(handle_, AUDIO_SETINFO, &info) < 0)
+    {
+        throw SnapException("Can't set channel count: " + string(strerror(errno)));
+    }
+
+    AUDIO_INITINFO(&info);
+
+    info.play.sample_rate = rate;
+
+    if (ioctl(handle_, AUDIO_SETINFO, &info) < 0)
+    {
+        throw SnapException("Can't set rate: " + string(strerror(errno)));
+    }
+
+    (void)ioctl(handle_, AUDIO_GETINFO, &info);
+
+    rate = info.play.sample_rate;
+
+    if (format.rate() != rate)
+        LOG(WARNING, LOG_TAG) << "Could not set sample rate to " << format.rate() << " Hz, using: " << rate << " Hz\n";
+
+    AUDIO_INITINFO(&info);
+    info.hiwat = PERIODS;
+    info.lowat = MIN_PERIODS;
+    (void)ioctl(handle_, AUDIO_SETINFO, &info);
+}
+
+
+void SunPlayer::uninitSun()
+{
+    std::lock_guard<std::recursive_mutex> lock(mutex_);
+    if (handle_ != -1)
+    {
+        close(handle_);
+        handle_ = -1;
+    }
+}
+
+
+void SunPlayer::start()
+{
+    try
+    {
+        initSun();
+    }
+    catch (const SnapException& e)
+    {
+        LOG(ERROR, LOG_TAG) << "Exception: " << e.what() << ", code: " << e.code() << "\n";
+        // Accept "Device or ressource busy", the worker loop will retry
+        if (e.code() != -EBUSY)
+            throw;
+    }
+
+    Player::start();
+}
+
+
+SunPlayer::~SunPlayer()
+{
+    stop();
+}
+
+
+void SunPlayer::stop()
+{
+    Player::stop();
+    uninitSun();
+}
+
+
+bool SunPlayer::needsThread() const
+{
+    return true;
+}
+
+void SunPlayer::worker()
+{
+    unsigned int framesDelay;
+    unsigned int framesAvail;
+    long lastChunkTick = chronos::getTickCount();
+    const SampleFormat& format = stream_->getFormat();
+    struct audio_info info;
+
+    while (active_)
+    {
+        if (handle_ == -1)
+        {
+            try
+            {
+                initSun();
+            }
+            catch (const std::exception& e)
+            {
+                LOG(ERROR, LOG_TAG) << "Exception in initSun: " << e.what() << endl;
+                chronos::sleep(100);
+            }
+            if (handle_ == -1)
+                continue;
+        }
+
+        if (ioctl(handle_, AUDIO_GETBUFINFO, &info) == -1) {
+            this_thread::sleep_for(10ms);
+            continue;
+        }
+
+        framesDelay = info.play.seek / format.frameSize();
+        framesAvail = (info.play.buffer_size - info.play.seek) / format.frameSize();
+
+        if (buffer_.size() < static_cast<size_t>(info.play.buffer_size))
+        {
+            LOG(DEBUG, LOG_TAG) << "Resizing buffer from " << buffer_.size() << " to " << info.play.buffer_size << "\n";
+            buffer_.resize(info.play.buffer_size);
+        }
+
+        if (framesAvail == 0)
+        {
+            auto frame_time = std::chrono::microseconds(static_cast<int>((info.blocksize / format.frameSize()) / format.usRate()));
+            std::chrono::microseconds wait = std::min(frame_time / 2, std::chrono::microseconds(10ms));
+            LOG(DEBUG, LOG_TAG) << "No frames available, waiting for " << wait.count() << " us\n";
+            this_thread::sleep_for(wait);
+            continue;
+        }
+
+
+        chronos::usec delay(static_cast<chronos::usec::rep>(1000 * static_cast<double>(framesDelay) / format.msRate()));
+
+        if (stream_->getPlayerChunk(buffer_.data(), delay, framesAvail))
+        {
+            lastChunkTick = chronos::getTickCount();
+            adjustVolume(buffer_.data(), framesAvail);
+            if (write(handle_, buffer_.data(), framesAvail * format.frameSize()) < 0)
+            {
+                LOG(ERROR, LOG_TAG) << "ERROR. Can't write to PCM device: " << strerror(errno) << "\n";
+                uninitSun();
+            }
+        }
+        else
+        {
+            LOG(INFO, LOG_TAG) << "Failed to get chunk\n";
+            while (active_ && !stream_->waitForChunk(100ms))
+            {
+                static utils::logging::TimeConditional cond(2s);
+                LOG(DEBUG, LOG_TAG) << cond << "Waiting for chunk\n";
+                if ((handle_ != -1) && (chronos::getTickCount() - lastChunkTick > 5000))
+                {
+                    LOG(NOTICE, LOG_TAG) << "No chunk received for 5000ms. Closing audio device.\n";
+                    uninitSun();
+                    stream_->clearChunks();
+                }
+            }
+        }
+    }
+}
+
+
+
+vector<PcmDevice> SunPlayer::pcm_list()
+{
+    std::string name;
+    struct audio_device dev;
+    vector<PcmDevice> result;
+    PcmDevice pcmDevice;
+    int i;
+    int fd;
+    int props;
+
+    for (i = 0; i < SUN_MAXDEVS; ++i)
+    {
+        name = "/dev/audio" + cpt::to_string(i);
+        fd = open(name.c_str(), O_WRONLY);
+        if (fd == -1)
+             break;
+        if (ioctl(fd, AUDIO_GETPROPS, &props) == -1)
+        {
+             close(fd);
+             break;
+        }
+        if (ioctl(fd, AUDIO_GETDEV, &dev) == -1)
+        {
+             close(fd);
+             break;
+        }
+        close(fd);
+        if ((props & AUDIO_PROP_PLAYBACK) == 0)
+        {
+             continue;
+        }
+        pcmDevice.name = name;
+        pcmDevice.description = string(dev.name) + " " + string(dev.version);
+        pcmDevice.idx = i;
+        result.push_back(pcmDevice);
+    }
+    return result;
+}
+
+} // namespace player
