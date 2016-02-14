$NetBSD: patch-memory_mozalloc_mozalloc__abort.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- memory/mozalloc/mozalloc_abort.cpp.orig	2015-01-09 04:38:22.000000000 +0000
+++ memory/mozalloc/mozalloc_abort.cpp
@@ -63,7 +63,11 @@ void fillAbortMessage(char (&msg)[N], ui
 // Define abort() here, so that it is used instead of the system abort(). This
 // lets us control the behavior when aborting, in order to get better results
 // on *NIX platforms. See mozalloc_abort for details.
+#if defined(SOLARIS)
+void std::abort(void)
+#else
 void abort(void)
+#endif
 {
 #ifdef MOZ_WIDGET_ANDROID
     char msg[64] = {};
