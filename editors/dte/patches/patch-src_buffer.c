$NetBSD: patch-src_buffer.c,v 1.1 2024/01/05 14:41:20 bacon Exp $

https://github.com/craigbarnes/dte/commit/77bec65e5f43ded39239a96cf8c26a5a599c31eb

--- src/buffer.c.orig	2023-03-01 23:29:00.000000000 +0000
+++ src/buffer.c
@@ -459,7 +459,8 @@ String dump_buffer(const Buffer *buffer)
     char modestr[12];
     char timestr[64];
     if (!timespec_to_str(&file->mtime, timestr, sizeof(timestr))) {
-        memcpy(timestr, STRN("[error]") + 1);
+        static const char msg[] = "[error]";
+        memcpy(timestr, msg, sizeof(msg));
     }
 
     string_sprintf (
