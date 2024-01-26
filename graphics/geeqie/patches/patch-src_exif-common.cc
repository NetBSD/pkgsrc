$NetBSD: patch-src_exif-common.cc,v 1.3 2024/01/26 14:13:01 wiz Exp $

With _XOPEN_SOURCE defined without value, NetBSD headers don't provide setenv().
https://github.com/BestImageViewer/geeqie/issues/1230

--- src/exif-common.cc.orig	2024-01-26 13:57:52.740080922 +0000
+++ src/exif-common.cc
@@ -19,7 +19,7 @@
 
 #include <config.h>
 
-#define _XOPEN_SOURCE
+//#define _XOPEN_SOURCE
 
 #include <cmath>
 #include <cstdlib>
