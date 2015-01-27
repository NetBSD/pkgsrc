$NetBSD: patch-coda-src_venus_venus.cc,v 1.1 2015/01/27 15:21:52 hauke Exp $

SunOS does not implicitly include <fcntl.h>.

--- ./coda-src/venus/venus.cc.orig	2009-02-13 20:51:05.000000000 +0000
+++ ./coda-src/venus/venus.cc
@@ -27,6 +27,7 @@ extern "C" {
 #include <sys/file.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <fcntl.h>
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/param.h>
