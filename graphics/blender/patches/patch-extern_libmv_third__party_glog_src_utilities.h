$NetBSD: patch-extern_libmv_third__party_glog_src_utilities.h,v 1.1 2012/12/03 13:15:51 ryoon Exp $

* NetBSD has no unwind

--- extern/libmv/third_party/glog/src/utilities.h.orig	2012-10-09 18:43:15.000000000 +0000
+++ extern/libmv/third_party/glog/src/utilities.h
@@ -101,7 +101,7 @@
 // correctly when GetStackTrace() is called with max_depth == 0.
 // Some code may do that.
 
-#if defined(__MINGW32__) || defined(__FreeBSD__)
+#if defined(__MINGW32__) || defined(__FreeBSD__) || defined(__NetBSD__)
 # undef STACKTRACE_H
 #elif defined(HAVE_LIB_UNWIND)
 # define STACKTRACE_H "stacktrace_libunwind-inl.h"
