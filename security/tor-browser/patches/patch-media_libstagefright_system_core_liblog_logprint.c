$NetBSD: patch-media_libstagefright_system_core_liblog_logprint.c,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- media/libstagefright/system/core/liblog/logprint.c.orig	2015-01-23 05:59:59.000000000 +0000
+++ media/libstagefright/system/core/liblog/logprint.c	2015-02-16 14:12:46.000000000 +0000
@@ -101,7 +101,7 @@
 {
     android_LogPriority pri;
 
-    c = tolower(c);
+    c = tolower((unsigned char)c);
 
     if (c >= '0' && c <= '9') {
         if (c >= ('0'+ANDROID_LOG_SILENT)) {
@@ -370,7 +370,7 @@
 {
     char *end = str + strlen(str) - 1;
 
-    while (end >= str && isspace(*end))
+    while (end >= str && isspace((unsigned char)*end))
         *end-- = '\0';
     return str;
 }
