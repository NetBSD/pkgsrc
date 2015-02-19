$NetBSD: patch-src_tools_anopesmtp.c,v 1.1 2015/02/19 22:24:24 joerg Exp $

--- src/tools/anopesmtp.c.orig	2015-02-19 19:29:39.000000000 +0000
+++ src/tools/anopesmtp.c
@@ -144,7 +144,8 @@ void alog(const char *fmt, ...)
 
     checkday();
 
-    if (!fmt) {
+    if (!fmt || !logfile) {
+        errno = errno_save;
         return;
     }
 
@@ -152,11 +153,9 @@ void alog(const char *fmt, ...)
     time(&t);
     tm = *localtime(&t);
     strftime(buf, sizeof(buf) - 1, "[%b %d %H:%M:%S %Y] ", &tm);
-    if (logfile && args) {
-        fputs(buf, logfile);
-        vfprintf(logfile, fmt, args);
-        fputc('\n', logfile);
-    }
+    fputs(buf, logfile);
+    vfprintf(logfile, fmt, args);
+    fputc('\n', logfile);
     va_end(args);
     errno = errno_save;
 }
