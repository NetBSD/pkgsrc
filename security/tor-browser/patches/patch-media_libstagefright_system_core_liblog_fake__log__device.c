$NetBSD: patch-media_libstagefright_system_core_liblog_fake__log__device.c,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- media/libstagefright/system/core/liblog/fake_log_device.c.orig	2015-01-23 05:59:59.000000000 +0000
+++ media/libstagefright/system/core/liblog/fake_log_device.c	2015-02-16 14:09:00.000000000 +0000
@@ -229,11 +229,11 @@
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
@@ -272,7 +272,7 @@
                 }
 
                 tags++;
-                if (*tags != '\0' && !isspace(*tags)) {
+                if (*tags != '\0' && !isspace((unsigned char)*tags)) {
                     TRACE("ERROR: garbage in tag env; expected whitespace\n");
                     TRACE("       env='%s'\n", tags);
                     return;
