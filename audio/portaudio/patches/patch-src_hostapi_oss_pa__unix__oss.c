$NetBSD: patch-src_hostapi_oss_pa__unix__oss.c,v 1.4 2020/04/15 17:12:14 nia Exp $

- Add 24-bit and 32-bit sample formats.
- NetBSD-specific changes to make this map better to the emulation layer:
  We don't need to initialize the stream by writing silence, etc.
  PaOssStream_WaitForFrames hangs forever unless disabled, this may be a bug.
- Add features needed to make portmixer work with audacity.

--- src/hostapi/oss/pa_unix_oss.c.orig	2016-10-30 01:23:04.000000000 +0000
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
@@ -938,6 +943,16 @@ static PaError Pa2OssFormat( PaSampleFor
         case paInt16:
             *ossFormat = AFMT_S16_NE;
             break;
+#ifdef AFMT_S24_NE
+        case paInt24:
+            *ossFormat = AFMT_S24_NE;
+            break;
+#endif
+#ifdef AFMT_S32_NE
+        case paInt32:
+            *ossFormat = AFMT_S32_NE;
+            break;
+#endif
         default:
             return paInternalError;     /* This shouldn't happen */
     }
@@ -961,6 +976,14 @@ static PaError GetAvailableFormats( PaOs
         frmts |= paInt8;
     if( mask & AFMT_S16_NE )
         frmts |= paInt16;
+#ifdef AFMT_S24_NE
+    if( mask & AFMT_S24_NE )
+        frmts |= paInt24;
+#endif
+#ifdef AFMT_S32_NE
+    if( mask & AFMT_S32_NE )
+        frmts |= paInt32;
+#endif
     else
         result = paSampleFormatNotSupported;
 
@@ -1040,12 +1063,23 @@ static PaError PaOssStreamComponent_Conf
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
@@ -1477,6 +1511,7 @@ static PaError PaOssStream_Prepare( PaOs
         size_t bufSz = PaOssStreamComponent_BufferSize( stream->playback );
         memset( stream->playback->buffer, 0, bufSz );
 
+#ifndef __NetBSD__
         /* Looks like we have to turn off blocking before we try this, but if we don't fill the buffer
          * OSS will complain. */
         PA_ENSURE( ModifyBlocking( stream->playback->fd, 0 ) );
@@ -1486,6 +1521,7 @@ static PaError PaOssStream_Prepare( PaOs
                 break;
         }
         PA_ENSURE( ModifyBlocking( stream->playback->fd, 1 ) );
+#endif
     }
 
     if( stream->sharedDevice )
@@ -1652,6 +1688,7 @@ static void *PaOSS_AudioThreadProc( void
             callbackResult = paComplete;
         }
 
+#ifndef __NetBSD__
         /* Aspect StreamState: Because of the messy OSS scheme we can't explicitly trigger device start unless
          * the stream has been recently started, we will have to go right ahead and read/write in blocking
          * fashion to trigger operation. Therefore we begin with processing one host buffer before we switch
@@ -1667,6 +1704,9 @@ static void *PaOSS_AudioThreadProc( void
         {
             framesAvail = stream->framesPerHostBuffer;
         }
+#else
+        framesAvail = stream->framesPerHostBuffer;
+#endif
 
         while( framesAvail > 0 )
         {
@@ -1749,11 +1789,13 @@ static void *PaOSS_AudioThreadProc( void
 
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
@@ -2043,3 +2085,26 @@ error:
 #endif
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
