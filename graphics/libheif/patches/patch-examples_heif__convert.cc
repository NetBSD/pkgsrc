$NetBSD: patch-examples_heif__convert.cc,v 1.3 2020/09/29 06:04:58 triaxx Exp $

Include alloca.h on SunOS

--- examples/heif_convert.cc.orig	2020-09-23 14:02:39.000000000 +0000
+++ examples/heif_convert.cc
@@ -27,8 +27,10 @@
 #include "config.h"
 #endif
 
-#if defined(_MSC_VER) || defined(__MINGW32__)
+#if defined(_MSC_VER) || defined(__MINGW32__) || defined(__NetBSD__)
 # include <malloc.h>
+#elif defined(__FreeBSD__)
+# include <stdlib.h>
 #else
 # include <alloca.h>
 #endif
