$NetBSD: patch-src_hostapi_oss_pa__unix__oss.c,v 1.1 2019/10/20 11:10:49 nia Exp $

Don't write an endless stream of silence when preparing the stream.

--- src/hostapi/oss/pa_unix_oss.c.orig	2016-10-30 01:23:04.000000000 +0000
+++ src/hostapi/oss/pa_unix_oss.c
@@ -1479,6 +1479,7 @@ static PaError PaOssStream_Prepare( PaOs
 
         /* Looks like we have to turn off blocking before we try this, but if we don't fill the buffer
          * OSS will complain. */
+#ifndef __NetBSD__
         PA_ENSURE( ModifyBlocking( stream->playback->fd, 0 ) );
         while (1)
         {
@@ -1486,6 +1487,7 @@ static PaError PaOssStream_Prepare( PaOs
                 break;
         }
         PA_ENSURE( ModifyBlocking( stream->playback->fd, 1 ) );
+#endif
     }
 
     if( stream->sharedDevice )
