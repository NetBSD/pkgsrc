$NetBSD: patch-coda-src_volutil_vol-ancient.cc,v 1.1 2015/01/27 15:21:52 hauke Exp $

SunOS does not implicitly include <limits.h>.

--- coda-src/volutil/vol-ancient.cc.orig	2006-05-27 16:03:34.000000000 +0000
+++ coda-src/volutil/vol-ancient.cc
@@ -21,6 +21,7 @@ extern "C" {
 #endif
 
 #include <sys/types.h>
+#include <limits.h>
 #include <errno.h>
 
 #include <lwp/lwp.h>
