$NetBSD: patch-src_common_option.c,v 1.1 2025/02/14 10:39:17 vins Exp $

Associate 'orange' color to its ANSI escape code.

--- src/common/option.c.orig	2025-02-14 09:05:56.473760877 +0000
+++ src/common/option.c
@@ -193,6 +193,7 @@ void ffOptionParseColorNoClear(const cha
             else FF_APPEND_COLOR_CODE_COND(magenta, FF_COLOR_FG_MAGENTA)
             else FF_APPEND_COLOR_CODE_COND(cyan, FF_COLOR_FG_CYAN)
             else FF_APPEND_COLOR_CODE_COND(white, FF_COLOR_FG_WHITE)
+            else FF_APPEND_COLOR_CODE_COND(orange, FF_COLOR_FG_ORANGE)
             else FF_APPEND_COLOR_CODE_COND(default, FF_COLOR_FG_DEFAULT)
             else FF_APPEND_COLOR_CODE_COND(light_black, FF_COLOR_FG_LIGHT_BLACK)
             else FF_APPEND_COLOR_CODE_COND(light_red, FF_COLOR_FG_LIGHT_RED)
