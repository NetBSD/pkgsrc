$NetBSD: patch-coda-src_volutil_vol-dump.cc,v 1.1 2015/01/27 15:21:52 hauke Exp $

SunOS does not implicitly include <limits.h>.

--- coda-src/volutil/vol-dump.cc.orig	2008-08-08 19:09:39.000000000 +0000
+++ coda-src/volutil/vol-dump.cc
@@ -50,6 +50,7 @@ extern "C" {
 #include <errno.h>
 #include <sys/stat.h>
 #include <stdio.h>
+#include <limits.h>  
 #include <sys/file.h>
 #include <netinet/in.h>
 
