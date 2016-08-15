$NetBSD: patch-extern_glog_src_base_mutex.h,v 1.1 2016/08/15 19:26:18 ryoon Exp $

--- extern/glog/src/base/mutex.h.orig	2016-03-23 08:49:49.000000000 +0000
+++ extern/glog/src/base/mutex.h
@@ -133,7 +133,7 @@
   // out, but then you'd have to unset HAVE_RWLOCK (at least on linux -- it
   // *does* cause problems for FreeBSD, or MacOSX, but isn't needed
   // for locking there.)
-# ifdef __linux__
+# if defined(__linux__) || defined(__NetBSD__)
 #   ifndef _XOPEN_SOURCE  // Some other header might have already set it for us.
 #     define _XOPEN_SOURCE 500  // may be needed to get the rwlock calls
 #   endif
