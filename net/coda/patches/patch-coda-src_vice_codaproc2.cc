$NetBSD: patch-coda-src_vice_codaproc2.cc,v 1.1 2015/01/27 15:21:52 hauke Exp $

SunOS does not implicitly include <limits.h>.

--- coda-src/vice/codaproc2.cc.orig	2009-07-27 20:43:23.000000000 +0000
+++ coda-src/vice/codaproc2.cc
@@ -35,6 +35,7 @@ extern "C" {
 #endif
 
 #include <sys/types.h>
+#include <limits.h>  
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/file.h>
