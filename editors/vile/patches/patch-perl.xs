$NetBSD: patch-perl.xs,v 1.1 2022/07/06 09:18:24 wiz Exp $

Fix build with perl 5.36 from author Thomas E. Dickey via
https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=1014289

--- perl.xs.orig	2021-12-07 01:40:25.000000000 +0000
+++ perl.xs
@@ -21,7 +21,6 @@
  */
 #ifdef __GNUC__
 #pragma GCC diagnostic ignored "-Wcast-qual"
-#pragma GCC diagnostic ignored "-Wcompound-token-split-by-macro"
 #pragma GCC diagnostic ignored "-Wconversion"
 #pragma GCC diagnostic ignored "-Wnested-externs"
 #pragma GCC diagnostic ignored "-Wshadow"
@@ -119,20 +118,20 @@
 
 /* for vile */
 #define MARK vile_MARK
+#define regexp vile_regexp
 #include "estruct.h"
 #include "edef.h"
 #include "api.h"
+#undef regexp
 #undef MARK
 #undef ABORT
 
 /* for perl */
 #define main perl_main
-#define regexp perl_regexp
 #include <EXTERN.h>
 #include <perl.h>
 #include <XSUB.h>
 #undef main
-#undef regexp
 #undef dofile
 
 #ifdef __GNUC__
