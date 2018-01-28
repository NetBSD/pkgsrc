$NetBSD: patch-src_utils.c,v 1.1.2.2 2018/01/28 11:12:35 bsiegert Exp $

Don't overflow a buffer.

--- src/utils.c.orig	2004-04-14 01:48:17.000000000 +0000
+++ src/utils.c
@@ -137,7 +137,7 @@ print_separator(int bnl, int anl, u_int8
 #endif
 
     va_start(va, msgp);
-    vsnprintf(msg, 256, msgp, va);
+    vsnprintf(msg, 255, msgp, va);
 
     msg_len = strlen(msg);
 
