$NetBSD: patch-src_theorautils.c,v 1.1 2019/09/26 10:22:51 tron Exp $

Fix build problem under macOS

--- src/theorautils.c.orig	2016-01-10 04:35:56.000000000 +0000
+++ src/theorautils.c	2019-09-26 11:12:41.000000000 +0100
@@ -45,6 +45,7 @@
 #include <assert.h>
 #include <math.h>
 #include <limits.h>
+#include <inttypes.h>
 
 #ifdef WIN32
 #if !defined(fseeko)
