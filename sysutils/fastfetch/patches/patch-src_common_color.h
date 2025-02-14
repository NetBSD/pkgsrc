$NetBSD: patch-src_common_color.h,v 1.1 2025/02/14 10:39:17 vins Exp $

Define _ORANGE colors.

--- src/common/color.h.orig	2025-02-11 02:40:51.000000000 +0000
+++ src/common/color.h
@@ -18,6 +18,7 @@
 #define FF_COLOR_FG_MAGENTA "35"
 #define FF_COLOR_FG_CYAN "36"
 #define FF_COLOR_FG_WHITE "37"
+#define FF_COLOR_FG_ORANGE "38;2;255;133;"
 #define FF_COLOR_FG_DEFAULT "39"
 
 #define FF_COLOR_FG_LIGHT_BLACK "90"
@@ -37,6 +38,7 @@
 #define FF_COLOR_BG_MAGENTA "45"
 #define FF_COLOR_BG_CYAN "46"
 #define FF_COLOR_BG_WHITE "47"
+#define FF_COLOR_BG_ORANGE "48;2;255;133;"
 #define FF_COLOR_BG_DEFAULT "49"
 
 #define FF_COLOR_BG_LIGHT_BLACK "100"
