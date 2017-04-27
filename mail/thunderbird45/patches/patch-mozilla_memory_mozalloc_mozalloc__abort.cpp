$NetBSD: patch-mozilla_memory_mozalloc_mozalloc__abort.cpp,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/memory/mozalloc/mozalloc_abort.cpp.orig	2016-04-07 21:33:25.000000000 +0000
+++ mozilla/memory/mozalloc/mozalloc_abort.cpp
@@ -68,7 +68,11 @@ void fillAbortMessage(char (&msg)[N], ui
 //
 // That segmentation fault will be interpreted as another bug by ASan and as a
 // result, ASan will just exit(1) instead of aborting.
+#if defined(SOLARIS)
+void std::abort(void)
+#else
 void abort(void)
+#endif
 {
 #ifdef MOZ_WIDGET_ANDROID
     char msg[64] = {};
