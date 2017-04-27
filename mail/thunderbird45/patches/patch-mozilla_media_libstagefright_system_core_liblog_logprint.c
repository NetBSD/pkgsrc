$NetBSD: patch-mozilla_media_libstagefright_system_core_liblog_logprint.c,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/media/libstagefright/system/core/liblog/logprint.c.orig	2016-04-07 21:33:21.000000000 +0000
+++ mozilla/media/libstagefright/system/core/liblog/logprint.c
@@ -103,7 +103,7 @@ static android_LogPriority filterCharToP
 {
     android_LogPriority pri;
 
-    c = tolower(c);
+    c = tolower((unsigned char)c);
 
     if (c >= '0' && c <= '9') {
         if (c >= ('0'+ANDROID_LOG_SILENT)) {
@@ -372,7 +372,7 @@ static inline char * strip_end(char *str
 {
     char *end = str + strlen(str) - 1;
 
-    while (end >= str && isspace(*end))
+    while (end >= str && isspace((unsigned char)*end))
         *end-- = '\0';
     return str;
 }
