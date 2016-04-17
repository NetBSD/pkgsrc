$NetBSD: patch-mozilla_media_libstagefright_system_core_liblog_fake__log__device.c,v 1.2 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/media/libstagefright/system/core/liblog/fake_log_device.c.orig	2016-04-07 21:33:21.000000000 +0000
+++ mozilla/media/libstagefright/system/core/liblog/fake_log_device.c
@@ -231,11 +231,11 @@ static void configureInitialState(const 
             char tagName[kMaxTagLen];
             int i, minPrio;
 
-            while (isspace(*tags))
+            while (isspace((unsigned char)*tags))
                 tags++;
 
             i = 0;
-            while (*tags != '\0' && !isspace(*tags) && *tags != ':' &&
+            while (*tags != '\0' && !isspace((unsigned char)*tags) && *tags != ':' &&
                 i < kMaxTagLen)
             {
                 tagName[i++] = *tags++;
@@ -274,7 +274,7 @@ static void configureInitialState(const 
                 }
 
                 tags++;
-                if (*tags != '\0' && !isspace(*tags)) {
+                if (*tags != '\0' && !isspace((unsigned char)*tags)) {
                     TRACE("ERROR: garbage in tag env; expected whitespace\n");
                     TRACE("       env='%s'\n", tags);
                     return;
