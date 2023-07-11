$NetBSD: patch-Src_spin.y,v 1.1 2023/07/11 11:07:05 wiz Exp $

Add header for free().
https://github.com/nimble-code/Spin/commit/65b04bb72363583be496e6ce51de9a5d0d4cd5a0

--- Src/spin.y.orig	2019-12-06 21:02:43.000000000 +0000
+++ Src/spin.y
@@ -13,6 +13,7 @@
 #include <unistd.h>
 #endif
 #include <stdarg.h>
+#include <stdlib.h>
 
 #define YYMAXDEPTH	20000	/* default is 10000 */
 #define YYDEBUG		0
