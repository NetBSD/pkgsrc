$NetBSD: patch-netbsd_sun_JackSunDriver.cpp,v 1.4 2021/09/12 06:04:44 nia Exp $

Add NetBSD support.

--- netbsd/sun/JackSunDriver.cpp.orig	2021-09-12 05:59:47.195547055 +0000
+++ netbsd/sun/JackSunDriver.cpp
@@ -0,0 +1,569 @@
+/*
+Copyright (C) 2003-2007 Jussi Laako <jussi@sonarnerd.net>
+Copyright (C) 2008 Grame & RTL 2008
+
+This program is free software; you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation; either version 2 of the License, or
+(at your option) any later version.
+
+This program is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with this program; if not, write to the Free Software
+Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
+
+*/
+
+#include "driver_interface.h"
+#include "JackThreadedDriver.h"
+#include "JackDriverLoader.h"
+#include "JackSunDriver.h"
+#include "JackEngineControl.h"
+#include "JackGraphManager.h"
+#include "JackError.h"
+#include "JackTime.h"
+#include "JackShmMem.h"
+#include "memops.h"
+
+#include <sys/ioctl.h>
+#include <sys/audioio.h>
+#include <errno.h>
+#include <fcntl.h>
+#include <unistd.h>
+
+#include <iostream>
+#include <assert.h>
+#include <stdio.h>
+#include <stdlib.h>
+
+using namespace std;
+
+namespace Jack
+{
+
+inline int int2pow2(int x)	{ int r = 0; while ((1 << r) < x) r++; return r; }
+
+static inline void CopyAndConvertIn(jack_sample_t *dst, void *src, size_t nframes, int channel, int chcount, int bits)
+{
+    switch (bits) {
+
+		case 16: {
+		    signed short *s16src = (signed short*)src;
+            s16src += channel;
+            sample_move_dS_s16(dst, (char*)s16src, nframes, chcount<<1);
+			break;
+        }
+		case 24: {
+			signed int *s32src = (signed int*)src;
+            s32src += channel;
+            sample_move_dS_s24(dst, (char*)s32src, nframes, chcount<<2);
+			break;
+        }
+		case 32: {
+			signed int *s32src = (signed int*)src;
+            s32src += channel;
+            sample_move_dS_s32u24(dst, (char*)s32src, nframes, chcount<<2);
+			break;
+        }
+	}
+}
+
+static inline void CopyAndConvertOut(void *dst, jack_sample_t *src, size_t nframes, int channel, int chcount, int bits)
+{
+	switch (bits) {
+
+		case 16: {
+			signed short *s16dst = (signed short*)dst;
+            s16dst += channel;
+            sample_move_d16_sS((char*)s16dst, src, nframes, chcount<<1, NULL); // No dithering for now...
+			break;
+        }
+		case 24: {
+			signed int *s32dst = (signed int*)dst;
+            s32dst += channel;
+            sample_move_d24_sS((char*)s32dst, src, nframes, chcount<<2, NULL); // No dithering for now...
+			break;
+        }
+		case 32: {
+            signed int *s32dst = (signed int*)dst;
+            s32dst += channel;
+            sample_move_d32u24_sS((char*)s32dst, src, nframes, chcount<<2, NULL);
+			break;
+        }
+	}
+}
+
+int JackSunDriver::OpenInput()
+{
+    struct audio_info info;
+    int new_buffer_size;
+
+    if ((fInFD = open(fCaptureDriverName, O_RDONLY)) < 0) {
+        jack_error("JackSunDriver::OpenInput failed to open device : %s@%i, errno = %d", __FILE__, __LINE__, errno);
+        return -1;
+    }
+
+#ifdef AUDIO_GETFORMAT
+    if (fCaptureChannels == 0) {
+        if (ioctl(fInFD, AUDIO_GETFORMAT, &info) == 0) {
+            fCaptureChannels = info.record.channels;
+        }
+    }
+#else
+    if (fCaptureChannels == 0) {
+        fCaptureChannels = 2;
+    }
+#endif
+
+    jack_log("JackSunDriver::OpenInput input fInFD = %d", fInFD);
+
+    AUDIO_INITINFO(&info);
+    info.record.encoding = AUDIO_ENCODING_SLINEAR;
+    info.record.precision = fPrecision;
+    info.record.channels = fCaptureChannels;
+    info.record.sample_rate = fEngineControl->fSampleRate;
+
+    if (ioctl(fInFD, AUDIO_SETINFO, &info) == -1) {
+        jack_error("JackSunDriver::OpenInput failed to set device parameters : %s@%i, errno = %d", __FILE__, __LINE__, errno);
+        goto error;
+    }
+
+    if (ioctl(fInFD, AUDIO_GETINFO, &info) == -1) {
+        jack_error("JackSunDriver::OpenInput failed to get device paramters : %s@%i, errno = %d", __FILE__, __LINE__, errno);
+        goto error;
+    }
+
+    if (info.record.channels != fCaptureChannels) {
+        jack_info("JackSunDriver::OpenInput driver forced the number of capture channels %u", info.record.channels);
+        goto error;
+    }
+
+    if (info.record.sample_rate != fEngineControl->fSampleRate) {
+        jack_info("JackSunDriver::OpenInput driver forced the sample rate %u", info.record.sample_rate);
+    }
+
+    fInputBufferSize = info.blocksize;
+
+    new_buffer_size = fInputBufferSize / ((info.record.precision / NBBY) * fCaptureChannels);
+
+    JackAudioDriver::SetBufferSize(new_buffer_size); // never fails
+
+    fInputBuffer = (void*)calloc(fInputBufferSize, 1);
+    assert(fInputBuffer);
+    return 0;
+
+error:
+    ::close(fInFD);
+    return -1;
+}
+
+int JackSunDriver::OpenOutput()
+{
+    struct audio_info info;
+    int new_buffer_size;
+
+    if ((fOutFD = open(fPlaybackDriverName, O_WRONLY)) < 0) {
+        jack_error("JackSunDriver::OpenOutput failed to open device : %s@%i, errno = %d", __FILE__, __LINE__, errno);
+        return -1;
+    }
+
+#ifdef AUDIO_GETFORMAT
+    if (fPlaybackChannels == 0) {
+        if (ioctl(fOutFD, AUDIO_GETFORMAT, &info) == 0) {
+            fPlaybackChannels = info.play.channels;
+        }
+    }
+#else
+    if (fPlaybackChannels == 0) {
+        fPlaybackChannels = 2;
+    }
+#endif
+
+    jack_log("JackSunDriver::OpenOutput input fOutFD = %d", fOutFD);
+
+    AUDIO_INITINFO(&info);
+    info.hiwat = 2;
+    info.play.encoding = AUDIO_ENCODING_SLINEAR;
+    info.play.precision = fPrecision;
+    info.play.channels = fPlaybackChannels;
+    info.play.sample_rate = fEngineControl->fSampleRate;
+
+    if (ioctl(fOutFD, AUDIO_SETINFO, &info) == -1) {
+        jack_error("JackSunDriver::OpenOutput failed to set device parameters : %s@%i, errno = %d", __FILE__, __LINE__, errno);
+        goto error;
+    }
+
+    if (ioctl(fOutFD, AUDIO_GETINFO, &info) == -1) {
+        jack_error("JackSunDriver::OpenOutput failed to get device paramters : %s@%i, errno = %d", __FILE__, __LINE__, errno);
+        goto error;
+    }
+
+    if (info.play.precision != fPrecision) {
+        jack_info("JackSunDriver::OpenOutput driver forced the precision %u", info.play.precision);
+        goto error;
+    }
+
+    if (info.play.channels != fPlaybackChannels) {
+        jack_info("JackSunDriver::OpenOutput driver forced the number of capture channels %u", info.play.channels);
+        goto error;
+    }
+
+    if (info.play.sample_rate != fEngineControl->fSampleRate) {
+        jack_info("JackSunDriver::OpenOutput driver forced the sample rate %u", info.play.sample_rate);
+    }
+
+    fOutputBufferSize = info.blocksize;
+
+    new_buffer_size = fOutputBufferSize / ((info.play.precision / NBBY) * fPlaybackChannels);
+
+    JackAudioDriver::SetBufferSize(new_buffer_size); // never fails
+
+    fOutputBuffer = (void*)calloc(fOutputBufferSize, 1);
+    assert(fOutputBuffer);
+    return 0;
+
+error:
+    ::close(fOutFD);
+    return -1;
+}
+
+int JackSunDriver::Open(jack_nframes_t nframes,
+                      jack_nframes_t samplerate,
+                      bool capturing,
+                      bool playing,
+                      int inchannels,
+                      int outchannels,
+                      bool excl,
+                      bool monitor,
+                      const char* capture_driver_uid,
+                      const char* playback_driver_uid,
+                      jack_nframes_t capture_latency,
+                      jack_nframes_t playback_latency,
+                      int bits)
+{
+    // Generic JackAudioDriver Open
+    if (JackAudioDriver::Open(nframes, samplerate, capturing, playing, inchannels, outchannels, monitor,
+        capture_driver_uid, playback_driver_uid, capture_latency, playback_latency) != 0) {
+        return -1;
+    } else {
+
+        if (!fEngineControl->fSyncMode) {
+            jack_error("Cannot run in asynchronous mode, use the -S parameter for jackd");
+            return -1;
+        }
+
+        fRWMode |= ((capturing) ? kRead : 0);
+        fRWMode |= ((playing) ? kWrite : 0);
+        fPrecision = bits;
+
+        if (OpenAux() < 0) {
+            Close();
+            return -1;
+        } else {
+            return 0;
+        }
+    }
+}
+
+int JackSunDriver::Close()
+{
+    int res = JackAudioDriver::Close();
+    CloseAux();
+    return res;
+}
+
+
+int JackSunDriver::OpenAux()
+{
+    if ((fRWMode & kRead) && (OpenInput() < 0)) {
+        return -1;
+    }
+
+    if ((fRWMode & kWrite) && (OpenOutput() < 0)) {
+        return -1;
+    }
+
+    return 0;
+}
+
+void JackSunDriver::CloseAux()
+{
+    if (fRWMode & kRead && fInFD > 0) {
+        close(fInFD);
+        fInFD = -1;
+    }
+
+    if (fRWMode & kWrite && fOutFD > 0) {
+        close(fOutFD);
+        fOutFD = -1;
+    }
+
+    if (fInputBuffer)
+        free(fInputBuffer);
+    fInputBuffer = NULL;
+
+    if (fOutputBuffer)
+        free(fOutputBuffer);
+    fOutputBuffer = NULL;
+}
+
+int JackSunDriver::Read()
+{
+    if (fInFD < 0) {
+        // Keep begin cycle time
+        JackDriver::CycleTakeBeginTime();
+        return 0;
+    }
+
+    ssize_t count;
+
+    count = ::read(fInFD, fInputBuffer, fInputBufferSize);
+
+    struct audio_info info;
+
+#if 0
+    // XRun detection
+    if (ioctl(fInFD, AUDIO_GETBUFINFO, &info) != -1) {
+        if (info.record.error > 0) {
+            jack_error("JackSunDriver::Read overruns");
+            jack_time_t cur_time = GetMicroSeconds();
+            NotifyXRun(cur_time, float(cur_time - fBeginDateUst));   // Better this value than nothing...
+        }
+    }
+#endif
+
+    if (count < 0) {
+        jack_log("JackSunDriver::Read error = %s", strerror(errno));
+        return -1;
+    } else if (count < (int)fInputBufferSize) {
+        jack_error("JackSunDriver::Read error bytes read = %ld", count);
+        return -1;
+    } else {
+
+        // Keep begin cycle time
+        JackDriver::CycleTakeBeginTime();
+        for (int i = 0; i < fCaptureChannels; i++) {
+            if (fGraphManager->GetConnectionsNum(fCapturePortList[i]) > 0) {
+                CopyAndConvertIn(GetInputBuffer(i), fInputBuffer, fEngineControl->fBufferSize, i, fCaptureChannels, fPrecision);
+            }
+        }
+
+        return 0;
+    }
+}
+
+int JackSunDriver::Write()
+{
+    if (fOutFD < 0) {
+        // Keep end cycle time
+        JackDriver::CycleTakeEndTime();
+        return 0;
+    }
+
+    ssize_t count;
+
+    memset(fOutputBuffer, 0, fOutputBufferSize);
+    for (int i = 0; i < fPlaybackChannels; i++) {
+        if (fGraphManager->GetConnectionsNum(fPlaybackPortList[i]) > 0) {
+            CopyAndConvertOut(fOutputBuffer, GetOutputBuffer(i), fEngineControl->fBufferSize, i, fPlaybackChannels, fPrecision);
+        }
+    }
+
+    // Keep end cycle time
+    JackDriver::CycleTakeEndTime();
+    count = ::write(fOutFD, fOutputBuffer, fOutputBufferSize);
+
+    struct audio_info info;
+
+    // XRun detection
+    if (ioctl(fOutFD, AUDIO_GETBUFINFO, &info) != -1) {
+
+        if (info.play.error > 0) {
+            jack_error("JackSunDriver::Write underruns");
+            jack_time_t cur_time = GetMicroSeconds();
+            NotifyXRun(cur_time, float(cur_time - fBeginDateUst));   // Better this value than nothing...
+        }
+    }
+
+    if (count < 0) {
+        jack_log("JackSunDriver::Write error = %s", strerror(errno));
+        return -1;
+    } else if (count < (int)fOutputBufferSize) {
+        jack_error("JackSunDriver::Write error bytes written = %ld", count);
+        return -1;
+    } else {
+        return 0;
+    }
+}
+
+int JackSunDriver::SetBufferSize(jack_nframes_t buffer_size)
+{
+    CloseAux();
+    JackAudioDriver::SetBufferSize(buffer_size); // Generic change, never fails
+    return OpenAux();
+}
+
+int JackSunDriver::ProcessSync()
+{
+    // Read input buffers for the current cycle
+    if (Read() < 0) {
+        jack_error("ProcessSync: read error, skip cycle");
+        return 0;   // Non fatal error here, skip cycle, but continue processing...
+    }
+
+    if (fIsMaster) {
+        ProcessGraphSync();
+    } else {
+        ResumeRefNum();
+    }
+
+    // Write output buffers for the current cycle
+    if (Write() < 0) {
+        jack_error("JackAudioDriver::ProcessSync: write error, skip cycle");
+        return 0;   // Non fatal error here, skip cycle, but continue processing...
+    }
+
+    return 0;
+}
+
+} // end of namespace
+
+#ifdef __cplusplus
+extern "C"
+{
+#endif
+
+SERVER_EXPORT jack_driver_desc_t* driver_get_descriptor()
+{
+    jack_driver_desc_t * desc;
+    jack_driver_desc_filler_t filler;
+    jack_driver_param_value_t value;
+
+    desc = jack_driver_descriptor_construct("sun", JackDriverMaster, "Sun API based audio backend", &filler);
+
+    value.ui = SUN_DRIVER_DEF_FS;
+    jack_driver_descriptor_add_parameter(desc, &filler, "rate", 'r', JackDriverParamUInt, &value, NULL, "Sample rate", NULL);
+
+    value.ui = SUN_DRIVER_DEF_BLKSIZE;
+    jack_driver_descriptor_add_parameter(desc, &filler, "period", 'p', JackDriverParamUInt, &value, NULL, "Frames per period", NULL);
+
+    value.i = SUN_DRIVER_DEF_BITS;
+    jack_driver_descriptor_add_parameter(desc, &filler, "wordlength", 'w', JackDriverParamInt, &value, NULL, "Word length", NULL);
+
+    value.ui = SUN_DRIVER_DEF_INS;
+    jack_driver_descriptor_add_parameter(desc, &filler, "inchannels", 'i', JackDriverParamUInt, &value, NULL, "Capture channels", NULL);
+
+    value.ui = SUN_DRIVER_DEF_OUTS;
+    jack_driver_descriptor_add_parameter(desc, &filler, "outchannels", 'o', JackDriverParamUInt, &value, NULL, "Playback channels", NULL);
+
+    strcpy(value.str, SUN_DRIVER_DEF_DEV);
+    jack_driver_descriptor_add_parameter(desc, &filler, "capture", 'C', JackDriverParamString, &value, NULL, "Input device", NULL);
+    jack_driver_descriptor_add_parameter(desc, &filler, "playback", 'P', JackDriverParamString, &value, NULL, "Output device", NULL);
+    jack_driver_descriptor_add_parameter(desc, &filler, "device", 'd', JackDriverParamString, &value, NULL, "Audio device name", NULL);
+
+    value.ui = 0;
+    jack_driver_descriptor_add_parameter(desc, &filler, "input-latency", 'I', JackDriverParamUInt, &value, NULL, "Extra input latency", NULL);
+    jack_driver_descriptor_add_parameter(desc, &filler, "output-latency", 'O', JackDriverParamUInt, &value, NULL, "Extra output latency", NULL);
+
+    return desc;
+}
+
+SERVER_EXPORT Jack::JackDriverClientInterface* driver_initialize(Jack::JackLockedEngine* engine, Jack::JackSynchro* table, const JSList* params)
+{
+    int bits = SUN_DRIVER_DEF_BITS;
+    jack_nframes_t srate = SUN_DRIVER_DEF_FS;
+    jack_nframes_t frames_per_interrupt = SUN_DRIVER_DEF_BLKSIZE;
+    const char* capture_pcm_name = SUN_DRIVER_DEF_DEV;
+    const char* playback_pcm_name = SUN_DRIVER_DEF_DEV;
+    bool capture = false;
+    bool playback = false;
+    int chan_in = 0;
+    int chan_out = 0;
+    bool monitor = false;
+    bool excl = false;
+    const JSList *node;
+    const jack_driver_param_t *param;
+    jack_nframes_t systemic_input_latency = 0;
+    jack_nframes_t systemic_output_latency = 0;
+
+    for (node = params; node; node = jack_slist_next(node)) {
+
+        param = (const jack_driver_param_t *)node->data;
+
+        switch (param->character) {
+
+        case 'r':
+            srate = param->value.ui;
+            break;
+
+        case 'p':
+            frames_per_interrupt = (unsigned int)param->value.ui;
+            break;
+
+        case 'w':
+            bits = param->value.i;
+            break;
+
+        case 'i':
+            chan_in = (int)param->value.ui;
+            break;
+
+        case 'o':
+            chan_out = (int)param->value.ui;
+            break;
+
+        case 'C':
+            capture = true;
+            if (strcmp(param->value.str, "none") != 0) {
+                capture_pcm_name = param->value.str;
+            }
+            break;
+
+        case 'P':
+            playback = true;
+            if (strcmp(param->value.str, "none") != 0) {
+                playback_pcm_name = param->value.str;
+            }
+            break;
+
+        case 'd':
+            playback_pcm_name = param->value.str;
+            capture_pcm_name = param->value.str;
+            break;
+
+        case 'I':
+            systemic_input_latency = param->value.ui;
+            break;
+
+        case 'O':
+            systemic_output_latency = param->value.ui;
+            break;
+        }
+    }
+
+    // duplex is the default
+    if (!capture && !playback) {
+        capture = true;
+        playback = true;
+    }
+
+    Jack::JackSunDriver* sun_driver = new Jack::JackSunDriver("system", "sun", engine, table);
+    Jack::JackDriverClientInterface* threaded_driver = new Jack::JackThreadedDriver(sun_driver);
+
+    // Special open for Sun driver...
+    if (sun_driver->Open(frames_per_interrupt, srate, capture, playback, chan_in, chan_out,
+        excl, monitor, capture_pcm_name, playback_pcm_name, systemic_input_latency, systemic_output_latency, bits) == 0) {
+        return threaded_driver;
+    } else {
+        delete threaded_driver; // Delete the decorated driver
+        return NULL;
+    }
+}
+
+#ifdef __cplusplus
+}
+#endif
