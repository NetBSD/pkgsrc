$NetBSD: patch-src_exif-common.cc,v 1.2 2023/06/17 16:50:53 wiz Exp $

../src/exif-common.cc:780:3: error: 'setenv' was not declared in this scope; did you mean 'getenv'?                                                                                                                
https://github.com/BestImageViewer/geeqie/pull/1110

--- src/exif-common.cc.orig	2023-06-17 12:12:30.000000000 +0000
+++ src/exif-common.cc
@@ -19,6 +19,8 @@
 
 #include <config.h>
 
+#include <stdlib.h>
+
 #define _XOPEN_SOURCE
 
 #include <string.h>
