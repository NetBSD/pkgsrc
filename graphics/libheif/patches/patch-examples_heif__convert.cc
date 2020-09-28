$NetBSD: patch-examples_heif__convert.cc,v 1.2 2020/09/28 13:38:13 ryoon Exp $

Include alloca.h on SunOS

--- examples/heif_convert.cc.orig	2020-09-23 14:02:39.000000000 +0000
+++ examples/heif_convert.cc
@@ -27,7 +27,7 @@
 #include "config.h"
 #endif
 
-#if defined(_MSC_VER) || defined(__MINGW32__)
+#if defined(_MSC_VER) || defined(__MINGW32__) || defined(__NetBSD__)
 # include <malloc.h>
 #else
 # include <alloca.h>
