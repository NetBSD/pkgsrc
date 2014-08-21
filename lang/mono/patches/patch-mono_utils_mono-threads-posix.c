$NetBSD: patch-mono_utils_mono-threads-posix.c,v 1.1 2014/08/21 07:49:56 wiz Exp $

--- mono/utils/mono-threads-posix.c.orig	2014-08-09 11:10:44.000000000 +0000
+++ mono/utils/mono-threads-posix.c
@@ -543,13 +543,21 @@ mono_threads_core_set_name (MonoNativeTh
 {
 #ifdef HAVE_PTHREAD_SETNAME_NP
 	if (!name) {
+#ifdef linux
 		pthread_setname_np (tid, "");
+#else
+		pthread_setname_np (tid, "%s", "");
+#endif
 	} else {
 		char n [16];
 
 		strncpy (n, name, 16);
 		n [15] = '\0';
+#ifdef linux
 		pthread_setname_np (tid, n);
+#else
+		pthread_setname_np (tid, "%s", n);
+#endif
 	}
 #endif
 }
