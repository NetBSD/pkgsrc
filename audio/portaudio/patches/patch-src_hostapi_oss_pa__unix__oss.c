$NetBSD: patch-src_hostapi_oss_pa__unix__oss.c,v 1.6 2024/07/16 11:40:16 adam Exp $

- Add 24-bit and 32-bit sample formats.
- NetBSD-specific changes to make this map better to the emulation layer:
  We don't need to initialize the stream by writing silence, etc.
  PaOssStream_WaitForFrames hangs forever unless disabled, this may be a bug.
- Add features needed to make portmixer work with audacity.

--- src/hostapi/oss/pa_unix_oss.c.orig	2021-04-01 00:35:42.000000000 +0000
+++ src/hostapi/oss/pa_unix_oss.c
@@ -65,7 +65,7 @@
 
 #ifdef HAVE_SYS_SOUNDCARD_H
 # include <sys/soundcard.h>
-# ifdef __NetBSD__
+# if defined(__NetBSD__) || defined(__OpenBSD__)
 #  define DEVICE_NAME_BASE           "/dev/audio"
 # else
 #  define DEVICE_NAME_BASE           "/dev/dsp"
@@ -417,7 +417,12 @@ static PaError QueryDirection( const cha
     /* Get supported sample rate closest to 44100 Hz */
     if( *defaultSampleRate < 0 )
     {
+#ifdef __NetBSD__
+        /* Less likely to require in-kernel conversion. */
+        sr = 48000;
+#else
         sr = 44100;
+#endif
         ENSURE_( ioctl( devHandle, SNDCTL_DSP_SPEED, &sr ), paUnanticipatedHostError );
 
         *defaultSampleRate = sr;
@@ -755,7 +760,7 @@ static PaError PaOssStreamComponent_Init
     component->devName = deviceName;
     component->userChannelCount = parameters->channelCount;
     component->userFormat = parameters->sampleFormat;
-    component->latency = parameters->suggestedLatency;
+    component->latency = parameters->suggestedLatency > 0 ? parameters->suggestedLatency : 1;
     component->userInterleaved = !(parameters->sampleFormat & paNonInterleaved);
 
     if( !callbackMode && !component->userInterleaved )
@@ -937,6 +942,11 @@ static PaError Pa2OssFormat( PaSampleFor
         case paInt16:
             *ossFormat = AFMT_S16_NE;
             break;
+#ifdef AFMT_S24_NE
+        case paInt24:
+            *ossFormat = AFMT_S24_NE;
+            break;
+#endif
 #ifdef AFMT_S32_NE
         case paInt32:
             *ossFormat = AFMT_S32_NE;
@@ -965,6 +975,10 @@ static PaError GetAvailableFormats( PaOs
         frmts |= paInt8;
     if( mask & AFMT_S16_NE )
         frmts |= paInt16;
+#ifdef AFMT_S24_NE
+    if( mask & AFMT_S24_NE )
+        frmts |= paInt24;
+#endif
 #ifdef AFMT_S32_NE
     if( mask & AFMT_S32_NE )
         frmts |= paInt32;
@@ -1048,12 +1062,23 @@ static PaError PaOssStreamComponent_Conf
         PA_ENSURE( Pa2OssFormat( hostFormat, &temp ) );
         nativeFormat = temp;
         ENSURE_( ioctl( component->fd, SNDCTL_DSP_SETFMT, &temp ), paUnanticipatedHostError );
+        PA_DEBUG(("%s: Wanted %d, selected format was %d\n", __FUNCTION__, nativeFormat, temp ));
         PA_UNLESS( temp == nativeFormat, paInternalError );
 
         /* try to set the number of channels */
         ENSURE_( ioctl( component->fd, SNDCTL_DSP_CHANNELS, &chans ), paSampleFormatNotSupported );   /* XXX: Should be paInvalidChannelCount? */
+#ifndef __NetBSD__
         /* It's possible that the minimum number of host channels is greater than what the user requested */
+        /* On NetBSD it's possible that the number is less than what the user requested, e.g. if the device is a mono mic */
         PA_UNLESS( chans >= component->userChannelCount, paInvalidChannelCount );
+#endif
+
+#ifdef __NetBSD__
+        /* Make the sample rate conform to hard kernel limits */
+        /* This can likely be removed after NetBSD 10... SNDCTL_DSP_SPEED should never return an error code. */
+        sr = sr > 192000 ? 192000 : sr;
+        sr = sr < 1000 ? 1000 : sr;
+#endif
 
         /* try to set the sample rate */
         ENSURE_( ioctl( component->fd, SNDCTL_DSP_SPEED, &sr ), paInvalidSampleRate );
@@ -1485,6 +1510,7 @@ static PaError PaOssStream_Prepare( PaOs
         size_t bufSz = PaOssStreamComponent_BufferSize( stream->playback );
         memset( stream->playback->buffer, 0, bufSz );
 
+#ifndef __NetBSD__
         /* Looks like we have to turn off blocking before we try this, but if we don't fill the buffer
          * OSS will complain. */
         PA_ENSURE( ModifyBlocking( stream->playback->fd, 0 ) );
@@ -1494,6 +1520,7 @@ static PaError PaOssStream_Prepare( PaOs
                 break;
         }
         PA_ENSURE( ModifyBlocking( stream->playback->fd, 1 ) );
+#endif
     }
 
     if( stream->sharedDevice )
@@ -1660,6 +1687,7 @@ static void *PaOSS_AudioThreadProc( void
             callbackResult = paComplete;
         }
 
+#ifndef __NetBSD__
         /* Aspect StreamState: Because of the messy OSS scheme we can't explicitly trigger device start unless
          * the stream has been recently started, we will have to go right ahead and read/write in blocking
          * fashion to trigger operation. Therefore we begin with processing one host buffer before we switch
@@ -1675,6 +1703,9 @@ static void *PaOSS_AudioThreadProc( void
         {
             framesAvail = stream->framesPerHostBuffer;
         }
+#else
+        framesAvail = stream->framesPerHostBuffer;
+#endif
 
         while( framesAvail > 0 )
         {
@@ -1757,11 +1788,13 @@ static void *PaOSS_AudioThreadProc( void
 
         if( initiateProcessing || !triggered )
         {
+#ifndef __NetBSD__
             /* Non-blocking */
             if( stream->capture )
                 PA_ENSURE( ModifyBlocking( stream->capture->fd, 0 ) );
             if( stream->playback && !stream->sharedDevice )
                 PA_ENSURE( ModifyBlocking( stream->playback->fd, 0 ) );
+#endif
 
             initiateProcessing = 0;
             sem_post( &stream->semaphore );
@@ -2032,6 +2065,29 @@ error:
     return result;
 }
 
+const char *PaOSS_GetStreamInputDevice( PaStream* s )
+{
+    PaOssStream *stream = (PaOssStream*)s;
+
+    if( stream->capture )
+    {
+      return stream->capture->devName;
+    }
+
+   return NULL;
+}
+
+const char *PaOSS_GetStreamOutputDevice( PaStream* s )
+{
+    PaOssStream *stream = (PaOssStream*)s;
+
+    if( stream->playback )
+    {
+      return stream->playback->devName;
+    }
+
+   return NULL;
+}
 
 /* TODO: Compute number of allocated bytes somewhere else, can we use ODELAY with capture */
 static signed long GetStreamWriteAvailable( PaStream* s )
