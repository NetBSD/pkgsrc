$NetBSD: patch-filter_filter__pp.c,v 1.1 2015/11/21 17:14:26 adam Exp $

Fixes building against FFmpeg version >= 2.0.0 (gentoo patch).

--- filter/filter_pp.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ filter/filter_pp.c
@@ -38,8 +38,8 @@
 
 /* FIXME: these use the filter ID as an index--the ID can grow
  * arbitrarily large, so this needs to be fixed */
-static pp_mode_t *mode[100];
-static pp_context_t *context[100];
+static pp_mode *mode[100];
+static pp_context *context[100];
 static int width[100], height[100];
 static int pre[100];
 
