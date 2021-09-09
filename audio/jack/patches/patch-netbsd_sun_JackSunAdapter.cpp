$NetBSD: patch-netbsd_sun_JackSunAdapter.cpp,v 1.2 2021/09/09 22:41:43 nia Exp $

Add NetBSD support.

--- netbsd/sun/JackSunAdapter.cpp.orig	2021-09-09 21:08:54.598607823 +0000
+++ netbsd/sun/JackSunAdapter.cpp
@@ -0,0 +1,490 @@
+/*
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
+#include "JackSunAdapter.h"
+#include "JackServerGlobals.h"
+#include "JackEngineControl.h"
+#include "memops.h"
+
+#include <sys/ioctl.h>
+#include <sys/audioio.h>
+#include <fcntl.h>
+#include <iostream>
+#include <assert.h>
+
+namespace Jack
+{
+
+inline int int2pow2(int x)	{ int r = 0; while ((1 << r) < x) r++; return r; }
+
+static inline void CopyAndConvertIn(jack_sample_t *dst, void *src, size_t nframes, int channel, int chcount, int bits)
+{
+#if 0
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
+#endif
+}
+
+static inline void CopyAndConvertOut(void *dst, jack_sample_t *src, size_t nframes, int channel, int chcount, int bits)
+{
+#if 0
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
+#endif
+}
+
+JackSunAdapter::JackSunAdapter(jack_nframes_t buffer_size, jack_nframes_t sample_rate, const JSList* params)
+                :JackAudioAdapterInterface(buffer_size, sample_rate)
+                ,fThread(this),
+                fInFD(-1), fOutFD(-1), fPrecision(SUN_DRIVER_DEF_BITS),
+                fRWMode(0),
+                fInputBufferSize(0), fOutputBufferSize(0),
+                fInputBuffer(NULL), fOutputBuffer(NULL)
+{
+    const JSList* node;
+    const jack_driver_param_t* param;
+
+    fCaptureChannels = 2;
+    fPlaybackChannels = 2;
+
+    strcpy(fCaptureDriverName, SUN_DRIVER_DEF_DEV);
+    strcpy(fPlaybackDriverName, SUN_DRIVER_DEF_DEV);
+
+    for (node = params; node; node = jack_slist_next(node)) {
+        param = (const jack_driver_param_t*) node->data;
+
+        switch (param->character) {
+
+            case 'r':
+                SetAdaptedSampleRate(param->value.ui);
+                break;
+
+            case 'p':
+                SetAdaptedBufferSize(param->value.ui);
+                break;
+
+            case 'w':
+                fPrecision = param->value.i;
+                break;
+
+            case 'i':
+                fCaptureChannels = param->value.ui;
+                break;
+
+            case 'o':
+                fPlaybackChannels = param->value.ui;
+                break;
+
+            case 'C':
+                fRWMode |= kRead;
+                if (strcmp(param->value.str, "none") != 0) {
+                   strcpy(fCaptureDriverName, param->value.str);
+                }
+                break;
+
+            case 'P':
+                fRWMode |= kWrite;
+                if (strcmp(param->value.str, "none") != 0) {
+                   strcpy(fPlaybackDriverName, param->value.str);
+                }
+                break;
+
+            case 'd':
+               fRWMode |= kRead;
+               fRWMode |= kWrite;
+               strcpy(fCaptureDriverName, param->value.str);
+               strcpy(fPlaybackDriverName, param->value.str);
+               break;
+
+            case 'q':
+                fQuality = param->value.ui;
+                break;
+
+            case 'g':
+                fRingbufferCurSize = param->value.ui;
+                fAdaptative = false;
+                break;
+
+           }
+    }
+
+    fRWMode |= kRead;
+    fRWMode |= kWrite;
+}
+
+void JackSunAdapter::DisplayDeviceInfo()
+{
+}
+
+int JackSunAdapter::OpenInput()
+{
+    struct audio_info info;
+
+    if ((fInFD = open(fCaptureDriverName, O_RDONLY)) < 0) {
+        jack_error("JackSunAdapter::OpenInput failed to open device : %s@%i, errno = %d", __FILE__, __LINE__, errno);
+        return -1;
+    }
+
+#ifdef AUDIO_GETFORMAT
+    if (fCaptureChannels == 0) {
+        if (ioctl(fInFD, AUDIO_GETFORMAT, &info) != -1) {
+            fCaptureChannels = info.record.channels;
+        }
+    }
+#else
+    if (fCaptureChannels == 0) {
+        fCaptureChannels = 2;
+    }
+#endif
+
+    jack_log("JackSunAdapter::OpenInput input fInFD = %d", fInFD);
+
+    AUDIO_INITINFO(&info);
+    info.record.encoding = AUDIO_ENCODING_SLINEAR;
+    info.record.precision = fPrecision;
+    info.record.channels = fCaptureChannels;
+    info.record.sample_rate = fAdaptedSampleRate;
+
+    if (ioctl(fInFD, AUDIO_SETINFO, &info) == -1) {
+        jack_error("JackSunAdapter::OpenInput failed to set device parameters : %s@%i, errno = %d", __FILE__, __LINE__, errno);
+        goto error;
+    }
+
+    if (ioctl(fInFD, AUDIO_GETINFO, &info) == -1) {
+        jack_error("JackSunAdapter::OpenInput failed to get device paramters : %s@%i, errno = %d", __FILE__, __LINE__, errno);
+        goto error;
+    }
+
+    if (info.record.channels != fCaptureChannels) {
+        jack_info("JackSunAdapter::OpenInput driver forced the number of capture channels %u", info.record.channels);
+        goto error;
+    }
+
+    if (info.record.sample_rate != fAdaptedSampleRate) {
+        jack_info("JackSunAdapter::OpenInput driver forced the sample rate %u", info.record.sample_rate);
+    }
+
+    fInputBufferSize = info.blocksize;
+    fInputBuffer = (void*)calloc(fInputBufferSize, 1);
+    assert(fInputBuffer);
+
+    fInputSampleBuffer = (float**)malloc(fCaptureChannels * sizeof(float*));
+    assert(fInputSampleBuffer);
+
+    for (int i = 0; i < fCaptureChannels; i++) {
+        fInputSampleBuffer[i] = (float*)malloc(fAdaptedBufferSize * sizeof(float));
+        assert(fInputSampleBuffer[i]);
+    }
+    return 0;
+
+error:
+    ::close(fInFD);
+    return -1;
+}
+
+int JackSunAdapter::OpenOutput()
+{
+    struct audio_info info;
+
+    if ((fOutFD = open(fPlaybackDriverName, O_WRONLY)) < 0) {
+        jack_error("JackSunAdapter::OpenOutput failed to open device : %s@%i, errno = %d", __FILE__, __LINE__, errno);
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
+    jack_log("JackSunAdapter::OpenOutput input fOutFD = %d", fOutFD);
+
+    AUDIO_INITINFO(&info);
+    info.hiwat = 2;
+    info.play.encoding = AUDIO_ENCODING_SLINEAR;
+    info.play.precision = fPrecision;
+    info.play.channels = fPlaybackChannels;
+    info.play.sample_rate = fAdaptedSampleRate;
+
+    if (ioctl(fOutFD, AUDIO_SETINFO, &info) == -1) {
+        jack_error("JackSunAdapter::OpenOutput failed to set device parameters : %s@%i, errno = %d", __FILE__, __LINE__, errno);
+        goto error;
+    }
+
+    if (ioctl(fOutFD, AUDIO_GETINFO, &info) == -1) {
+        jack_error("JackSunAdapter::OpenOutput failed to get device paramters : %s@%i, errno = %d", __FILE__, __LINE__, errno);
+        goto error;
+    }
+
+    if (info.play.precision != fPrecision) {
+        jack_info("JackSunAdapter::OpenOutput driver forced the precision %u", info.play.precision);
+        goto error;
+    }
+
+    if (info.play.channels != fPlaybackChannels) {
+        jack_info("JackSunAdapter::OpenOutput driver forced the number of capture channels %u", info.play.channels);
+        goto error;
+    }
+
+    if (info.play.sample_rate != fAdaptedSampleRate) {
+        jack_info("JackSunAdapter::OpenOutput driver forced the sample rate %u", info.play.sample_rate);
+    }
+
+    fOutputBufferSize = info.blocksize;
+    fOutputBuffer = (void*)calloc(fOutputBufferSize, 1);
+    assert(fOutputBuffer);
+
+    fOutputSampleBuffer = (float**)malloc(fPlaybackChannels * sizeof(float*));
+    assert(fOutputSampleBuffer);
+
+    for (int i = 0; i < fPlaybackChannels; i++) {
+        fOutputSampleBuffer[i] = (float*)malloc(fAdaptedBufferSize * sizeof(float));
+        assert(fOutputSampleBuffer[i]);
+    }
+
+    return 0;
+
+error:
+    ::close(fOutFD);
+    return -1;
+}
+
+int JackSunAdapter::Open()
+{
+    if ((fRWMode & kRead) && (OpenInput() < 0)) {
+        return -1;
+    }
+
+    if ((fRWMode & kWrite) && (OpenOutput() < 0)) {
+       return -1;
+    }
+
+    // In duplex mode, check that input and output use the same buffer size
+    if ((fRWMode & kRead) && (fRWMode & kWrite) && (fInputBufferSize != fOutputBufferSize)) {
+       jack_error("JackSunAdapter::OpenAux input and output buffer size are not the same!!");
+       goto error;
+    }
+
+    DisplayDeviceInfo();
+
+    //start adapter thread
+    if (fThread.StartSync() < 0) {
+        jack_error ( "Cannot start audioadapter thread" );
+        return -1;
+    }
+
+    //turn the thread realtime
+    fThread.AcquireRealTime(JackServerGlobals::fInstance->GetEngineControl()->fClientPriority);
+    return 0;
+
+error:
+    CloseAux();
+    return -1;
+}
+
+
+int JackSunAdapter::Close()
+{
+#ifdef JACK_MONITOR
+    fTable.Save(fHostBufferSize, fHostSampleRate, fAdaptedSampleRate, fAdaptedBufferSize);
+#endif
+    fThread.Stop();
+    CloseAux();
+    return 0;
+}
+
+void JackSunAdapter::CloseAux()
+{
+    if (fRWMode & kRead) {
+        close(fInFD);
+        fInFD = -1;
+    }
+
+    if (fRWMode & kWrite) {
+        close(fOutFD);
+        fOutFD = -1;
+    }
+
+    free(fInputBuffer);
+    fInputBuffer = NULL;
+
+    free(fOutputBuffer);
+    fOutputBuffer = NULL;
+
+    for (int i = 0; i < fCaptureChannels; i++) {
+        free(fInputSampleBuffer[i]);
+    }
+    free(fInputSampleBuffer);
+
+    for (int i = 0; i < fPlaybackChannels; i++) {
+        free(fOutputSampleBuffer[i]);
+    }
+    free(fOutputSampleBuffer);
+ }
+
+int JackSunAdapter::Read()
+{
+    ssize_t count = ::read(fInFD, fInputBuffer, fInputBufferSize);
+
+    if (count < fInputBufferSize) {
+        jack_error("JackSunAdapter::Read error bytes read = %ld", count);
+        return -1;
+    } else {
+        for (int i = 0; i < fCaptureChannels; i++) {
+             CopyAndConvertIn(fInputSampleBuffer[i], fInputBuffer, fAdaptedBufferSize, i, fCaptureChannels, fPrecision);
+        }
+        return 0;
+    }
+}
+
+int JackSunAdapter::Write()
+{
+    ssize_t count;
+
+    for (int i = 0; i < fPlaybackChannels; i++) {
+        CopyAndConvertOut(fOutputBuffer, fOutputSampleBuffer[i], fAdaptedBufferSize, i, fCaptureChannels, fPrecision);
+    }
+
+    count = ::write(fOutFD, fOutputBuffer, fOutputBufferSize);
+
+    if (count < fOutputBufferSize) {
+        jack_error("JackSunAdapter::Write error bytes written = %ld", count);
+        return -1;
+    } else {
+        return 0;
+    }
+}
+
+bool JackSunAdapter::Execute()
+{
+    //read data from audio interface
+    if (Read() < 0)
+        return false;
+
+    PushAndPull(fInputSampleBuffer, fOutputSampleBuffer, fAdaptedBufferSize);
+
+    //write data to audio interface
+    if (Write() < 0)
+        return false;
+
+    return true;
+}
+
+int JackSunAdapter::SetBufferSize(jack_nframes_t buffer_size)
+{
+    JackAudioAdapterInterface::SetBufferSize(buffer_size);
+    Close();
+    return Open();
+}
+
+} // namespace
+
+#ifdef __cplusplus
+extern "C"
+{
+#endif
+
+    SERVER_EXPORT jack_driver_desc_t* jack_get_descriptor()
+    {
+        jack_driver_desc_t * desc;
+        jack_driver_desc_filler_t filler;
+        jack_driver_param_value_t value;
+
+        desc = jack_driver_descriptor_construct("audioadapter", JackDriverNone, "netjack audio <==> net backend adapter", &filler);
+
+        value.ui = SUN_DRIVER_DEF_FS;
+        jack_driver_descriptor_add_parameter(desc, &filler, "rate", 'r', JackDriverParamUInt, &value, NULL, "Sample rate", NULL);
+
+        value.ui = SUN_DRIVER_DEF_BLKSIZE;
+        jack_driver_descriptor_add_parameter(desc, &filler, "period", 'p', JackDriverParamUInt, &value, NULL, "Frames per period", NULL);
+
+        value.i = SUN_DRIVER_DEF_BITS;
+        jack_driver_descriptor_add_parameter(desc, &filler, "wordlength", 'w', JackDriverParamInt, &value, NULL, "Word length", NULL);
+
+        value.ui = SUN_DRIVER_DEF_INS;
+        jack_driver_descriptor_add_parameter(desc, &filler, "in-channels", 'i', JackDriverParamUInt, &value, NULL, "Capture channels", NULL);
+
+        value.ui = SUN_DRIVER_DEF_OUTS;
+        jack_driver_descriptor_add_parameter(desc, &filler, "out-channels", 'o', JackDriverParamUInt, &value, NULL, "Playback channels", NULL);
+
+        strcpy(value.str, SUN_DRIVER_DEF_DEV);
+        jack_driver_descriptor_add_parameter(desc, &filler, "capture", 'C', JackDriverParamString, &value, NULL, "Input device", NULL);
+        jack_driver_descriptor_add_parameter(desc, &filler, "playback", 'P', JackDriverParamString, &value, NULL, "Output device", NULL);
+        jack_driver_descriptor_add_parameter(desc, &filler, "device", 'd', JackDriverParamString, &value, NULL, "Audio device name", NULL);
+
+        value.i  = true;
+        jack_driver_descriptor_add_parameter(desc, &filler, "ignorehwbuf", 'b', JackDriverParamBool, &value, NULL, "Ignore hardware period size", NULL);
+
+        value.ui  = 0;
+        jack_driver_descriptor_add_parameter(desc, &filler, "quality", 'q', JackDriverParamInt, &value, NULL, "Resample algorithm quality (0 - 4)", NULL);
+
+        value.i = 32768;
+        jack_driver_descriptor_add_parameter(desc, &filler, "ring-buffer", 'g', JackDriverParamInt, &value, NULL, "Fixed ringbuffer size", "Fixed ringbuffer size (if not set => automatic adaptative)");
+
+        return desc;
+    }
+
+#ifdef __cplusplus
+}
+#endif
+
