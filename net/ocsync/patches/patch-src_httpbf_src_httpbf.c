$NetBSD: patch-src_httpbf_src_httpbf.c,v 1.1 2021/01/13 09:40:40 nia Exp $

Fix build with gcc>=5, use c99-compliant identifier.

--- src/httpbf/src/httpbf.c.orig	2013-10-18 13:11:09.000000000 +0000
+++ src/httpbf/src/httpbf.c
@@ -42,7 +42,7 @@
 #define DEBUG_HBF(...) { if(transfer->log_cb) { \
         char buf[1024];                         \
         snprintf(buf, 1024, __VA_ARGS__);       \
-        transfer->log_cb(__FUNCTION__, buf);    \
+        transfer->log_cb(__func__, buf);    \
   }  }
 
 // #endif
