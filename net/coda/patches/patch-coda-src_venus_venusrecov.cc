$NetBSD: patch-coda-src_venus_venusrecov.cc,v 1.3 2015/01/27 15:21:52 hauke Exp $

SunOS does not implicitly include <limits.h>.

--- ./coda-src/venus/venusrecov.cc.orig	2008-10-06 16:52:18.000000000 +0000
+++ ./coda-src/venus/venusrecov.cc
@@ -35,6 +35,7 @@ extern "C" {
 #include <stdio.h>
 #include "coda_string.h"
 #include <sys/param.h>
+#include <limits.h>
 #include <sys/file.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
