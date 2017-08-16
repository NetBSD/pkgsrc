$NetBSD: patch-http.c,v 1.1 2017/08/16 15:18:24 jperkin Exp $

Support sig_t on SunOS.

--- http.c.orig	2017-06-28 12:50:49.000000000 +0000
+++ http.c
@@ -52,6 +52,10 @@ struct mem_chunk {
 	size_t len;
 };
 
+#ifdef __sun
+typedef void (*sig_t)();
+#endif
+
 #ifndef TEST_BUILD
 static bool interrupted = false;
 static sig_t previous_handler = SIG_DFL;
