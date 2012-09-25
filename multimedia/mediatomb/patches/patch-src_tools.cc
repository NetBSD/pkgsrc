$NetBSD: patch-src_tools.cc,v 1.1 2012/09/25 11:45:11 ryoon Exp $

Add SONY Bravia support
http://blog-imgs-30.fc2.com/h/o/r/horip/mediatomb-0_12_1_bravia_support_0_1_patch.txt

--- src/tools.cc.orig	2010-03-25 14:58:11.000000000 +0000
+++ src/tools.cc
@@ -435,7 +435,41 @@ String mime_types_to_CSV(Ref<Array<Strin
         if (i > 0)
             *buf << ",";
         String mimeType = mimeTypes->get(i);
-        *buf << "http-get:*:" << mimeType << ":*";
+//        *buf << "http-get:*:" << mimeType << ":*";
+
+        *buf << "http-get:*:" << mimeType;
+
+        log_debug("mimeType: %s..\n", mimeType.c_str() );
+//        log_debug("mimeType: %d\n", strcmp(mimeType.c_str(),"video/mpeg"));
+
+        // Add ORG_PN for mimetype that are unnecessary to be trancodeed. // horipiri
+        // Insert video/mpeg if mimeType=video/avi for BRAVIA's server diagnose. // horipiri
+        if (strstr(mimeType.c_str(),"video/mpeg")){
+                *buf << ":DLNA.ORG_PN=MPEG_PS_NTSC";
+        } 
+        else if (       (strstr(mimeType.c_str(),"video/avi")) 
+                     || (strstr(mimeType.c_str(),"video/x-flv"))
+                ) {
+                *buf << ":*,http-get:*:video/mpeg:DLNA.ORG_PN=MPEG_PS_NTSC";
+        } 
+        else if (strstr(mimeType.c_str(),"audio/L16")){
+                *buf << ":DLNA.ORG_PN=LPCM";
+        }
+        else if (strstr(mimeType.c_str(),"audio/mpeg")){
+                *buf << ":DLNA.ORG_PN=MP3";
+        }
+        else if (strstr(mimeType.c_str(),"application/ogg")){
+                *buf << ":*,http-get:*:audio/mpeg:DLNA.ORG_PN=MP3";
+        } 
+        else if (strstr(mimeType.c_str(),"image/jpeg")){
+                *buf << ":DLNA.ORG_PN=JPEG_LRG";
+        }
+        else if (strstr(mimeType.c_str(),"video/vnd.dlna.mpeg-tts")){
+                *buf << ":DLNA.ORG_PN=MPEG_TS_SD_60_AC3_T";
+        }
+        else {
+                *buf << ":*";
+         }
     }
 
     return buf->toString();
