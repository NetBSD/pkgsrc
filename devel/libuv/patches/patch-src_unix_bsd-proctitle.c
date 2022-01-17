$NetBSD: patch-src_unix_bsd-proctitle.c,v 1.1 2022/01/17 01:38:53 tnn Exp $

Only destroy the process title mutex if it had been initialized.

--- src/unix/bsd-proctitle.c.orig	2022-01-04 14:18:00.000000000 +0000
+++ src/unix/bsd-proctitle.c
@@ -27,6 +27,7 @@
 
 
 static uv_mutex_t process_title_mutex;
+static int process_title_mutex_inited = 0;
 static uv_once_t process_title_mutex_once = UV_ONCE_INIT;
 static char* process_title;
 
@@ -34,11 +35,13 @@ static char* process_title;
 static void init_process_title_mutex_once(void) {
   if (uv_mutex_init(&process_title_mutex))
     abort();
+  process_title_mutex_inited = 1;
 }
 
 
 void uv__process_title_cleanup(void) {
-  uv_mutex_destroy(&process_title_mutex);
+  if (process_title_mutex_inited)
+    uv_mutex_destroy(&process_title_mutex);
 }
 
 
