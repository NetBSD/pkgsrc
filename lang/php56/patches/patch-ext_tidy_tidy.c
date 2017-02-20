$NetBSD: patch-ext_tidy_tidy.c,v 1.1 2017/02/20 09:35:17 wiz Exp $

--- ext/tidy/tidy.c.orig	2017-01-19 00:17:47.000000000 +0000
+++ ext/tidy/tidy.c
@@ -31,7 +31,7 @@
 #include "ext/standard/info.h"
 
 #include "tidy.h"
-#include "buffio.h"
+#include "tidybuffio.h"
 
 /* compatibility with older versions of libtidy */
 #ifndef TIDY_CALL
