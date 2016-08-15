$NetBSD: patch-extern_glog_src_utilities.h,v 1.1 2016/08/15 19:26:18 ryoon Exp $

--- extern/glog/src/utilities.h.orig	2016-03-23 08:49:49.000000000 +0000
+++ extern/glog/src/utilities.h
@@ -101,7 +101,7 @@
 // correctly when GetStackTrace() is called with max_depth == 0.
 // Some code may do that.
 
-#if defined(__MINGW32__) || defined(__FreeBSD__)
+#if defined(__MINGW32__) || defined(__FreeBSD__) || defined(__NetBSD__)
 # undef STACKTRACE_H
 #elif defined(HAVE_LIB_UNWIND)
 # define STACKTRACE_H "stacktrace_libunwind-inl.h"
