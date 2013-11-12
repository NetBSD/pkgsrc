$NetBSD: patch-mozilla_memory_mozalloc_mozalloc__abort.cpp,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/memory/mozalloc/mozalloc_abort.cpp.orig	2013-10-23 22:09:13.000000000 +0000
+++ mozilla/memory/mozalloc/mozalloc_abort.cpp
@@ -34,7 +34,11 @@ mozalloc_abort(const char* const msg)
 // Define abort() here, so that it is used instead of the system abort(). This
 // lets us control the behavior when aborting, in order to get better results
 // on *NIX platforms. See mozalloc_abort for details.
+#if defined(SOLARIS)
+void std::abort(void)
+#else
 void abort(void)
+#endif
 {
     mozalloc_abort("Redirecting call to abort() to mozalloc_abort\n");
 }
