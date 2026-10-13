$NetBSD: patch-src_expr__parser.c,v 1.1 2026/10/13 08:36:47 drixter Exp $

AC_HEADER_STDC is obsolete, all pkgsrc supported platforms should
likely have them.

--- src/expr_parser.c.orig	2026-10-12 19:01:52.368089909 +0000
+++ src/expr_parser.c
@@ -37,10 +37,8 @@
 #include "config.h"
 #endif
 
-#ifdef STDC_HEADERS
 #include <stdio.h>
 #include <stdlib.h>
-#endif
 
 #ifdef HAVE_ERRNO_H
 #include <errno.h>
