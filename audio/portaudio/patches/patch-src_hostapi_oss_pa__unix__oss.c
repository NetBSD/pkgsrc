$NetBSD: patch-src_hostapi_oss_pa__unix__oss.c,v 1.3 2019/11/24 13:15:15 nia Exp $

Remove some rather pointless assertions that are incompatible with NetBSD's OSS
emulation layer.

Don't write an endless stream of silence when preparing the stream and don't try to
use OSS in non-blocking mode or poll it on NetBSD, this is unsupported.

Add features needed to make portmixer work with audacity.

--- src/hostapi/oss/pa_unix_oss.c.orig	2016-10-30 01:23:04.000000000 +0000
+++ src/hostapi/oss/pa_unix_oss.c
@@ -1040,23 +1040,13 @@ static PaError PaOssStreamComponent_Conf
         PA_ENSURE( Pa2OssFormat( hostFormat, &temp ) );
         nativeFormat = temp;
         ENSURE_( ioctl( component->fd, SNDCTL_DSP_SETFMT, &temp ), paUnanticipatedHostError );
-        PA_UNLESS( temp == nativeFormat, paInternalError );
 
         /* try to set the number of channels */
         ENSURE_( ioctl( component->fd, SNDCTL_DSP_CHANNELS, &chans ), paSampleFormatNotSupported );   /* XXX: Should be paInvalidChannelCount? */
-        /* It's possible that the minimum number of host channels is greater than what the user requested */
-        PA_UNLESS( chans >= component->userChannelCount, paInvalidChannelCount );
 
         /* try to set the sample rate */
         ENSURE_( ioctl( component->fd, SNDCTL_DSP_SPEED, &sr ), paInvalidSampleRate );
 
-        /* reject if there's no sample rate within 1% of the one requested */
-        if( (fabs( sampleRate - sr ) / sampleRate) > 0.01 )
-        {
-            PA_DEBUG(("%s: Wanted %f, closest sample rate was %d\n", __FUNCTION__, sampleRate, sr ));
-            PA_ENSURE( paInvalidSampleRate );
-        }
-
         ENSURE_( ioctl( component->fd, streamMode == StreamMode_In ? SNDCTL_DSP_GETISPACE : SNDCTL_DSP_GETOSPACE, &bufInfo ),
                 paUnanticipatedHostError );
         component->numBufs = bufInfo.fragstotal;
@@ -1477,6 +1467,7 @@ static PaError PaOssStream_Prepare( PaOs
         size_t bufSz = PaOssStreamComponent_BufferSize( stream->playback );
         memset( stream->playback->buffer, 0, bufSz );
 
+#ifndef __NetBSD__
         /* Looks like we have to turn off blocking before we try this, but if we don't fill the buffer
          * OSS will complain. */
         PA_ENSURE( ModifyBlocking( stream->playback->fd, 0 ) );
@@ -1486,6 +1477,7 @@ static PaError PaOssStream_Prepare( PaOs
                 break;
         }
         PA_ENSURE( ModifyBlocking( stream->playback->fd, 1 ) );
+#endif
     }
 
     if( stream->sharedDevice )
@@ -1652,6 +1644,7 @@ static void *PaOSS_AudioThreadProc( void
             callbackResult = paComplete;
         }
 
+#ifndef __NetBSD__
         /* Aspect StreamState: Because of the messy OSS scheme we can't explicitly trigger device start unless
          * the stream has been recently started, we will have to go right ahead and read/write in blocking
          * fashion to trigger operation. Therefore we begin with processing one host buffer before we switch
@@ -1667,6 +1660,9 @@ static void *PaOSS_AudioThreadProc( void
         {
             framesAvail = stream->framesPerHostBuffer;
         }
+#else
+        framesAvail = stream->framesPerHostBuffer;
+#endif
 
         while( framesAvail > 0 )
         {
@@ -1749,11 +1745,13 @@ static void *PaOSS_AudioThreadProc( void
 
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
@@ -2043,3 +2041,26 @@ error:
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
