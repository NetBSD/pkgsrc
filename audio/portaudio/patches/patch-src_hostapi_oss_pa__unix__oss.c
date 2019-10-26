$NetBSD: patch-src_hostapi_oss_pa__unix__oss.c,v 1.2 2019/10/26 17:22:08 nia Exp $

Don't write an endless stream of silence when preparing the stream.

Add features needed to make portmixer work with audacity.

--- src/hostapi/oss/pa_unix_oss.c.orig	2016-10-30 01:23:04.000000000 +0000
+++ src/hostapi/oss/pa_unix_oss.c
@@ -1477,6 +1477,7 @@ static PaError PaOssStream_Prepare( PaOs
         size_t bufSz = PaOssStreamComponent_BufferSize( stream->playback );
         memset( stream->playback->buffer, 0, bufSz );
 
+#ifndef __NetBSD__
         /* Looks like we have to turn off blocking before we try this, but if we don't fill the buffer
          * OSS will complain. */
         PA_ENSURE( ModifyBlocking( stream->playback->fd, 0 ) );
@@ -1486,6 +1487,7 @@ static PaError PaOssStream_Prepare( PaOs
                 break;
         }
         PA_ENSURE( ModifyBlocking( stream->playback->fd, 1 ) );
+#endif
     }
 
     if( stream->sharedDevice )
@@ -2043,3 +2045,26 @@ error:
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
