$NetBSD: patch-src_unix_bsd-proctitle.c,v 1.2 2022/01/17 10:12:54 tnn Exp $

https://github.com/libuv/libuv/pull/3428/commits/4ea2e7629dcedac0eb84bdc85861fbc51386e20b

--- src/unix/bsd-proctitle.c.orig	2022-01-04 14:18:00.000000000 +0000
+++ src/unix/bsd-proctitle.c
@@ -38,6 +38,7 @@ static void init_process_title_mutex_onc
 
 
 void uv__process_title_cleanup(void) {
+  uv_once(&process_title_mutex_once, init_process_title_mutex_once);
   uv_mutex_destroy(&process_title_mutex);
 }
 
