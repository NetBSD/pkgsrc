$NetBSD: patch-coda-src_venus_fso_dir.cc,v 1.1 2015/01/27 15:21:52 hauke Exp $

SunOS does not implicitly include <fcntl.h>.

--- ./coda-src/venus/fso_dir.cc.orig	2010-03-23 18:10:43.000000000 +0000
+++ ./coda-src/venus/fso_dir.cc
@@ -35,6 +35,7 @@ extern "C" {
 #include <sys/types.h>
 #include <sys/file.h>
 #include <sys/stat.h>
+#include <fcntl.h>
 #include <errno.h>
 #include "coda_string.h"
 #include <unistd.h>
