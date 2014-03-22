$NetBSD: patch-src_lib_engines_common_evas__font__load.c,v 1.1 2014/03/22 20:15:20 spz Exp $

make it deal gracefully with both freetype 2.4.* and 2.5.*

--- src/lib/engines/common/evas_font_load.c.orig	2013-04-04 18:00:09.000000000 +0000
+++ src/lib/engines/common/evas_font_load.c
@@ -5,7 +5,8 @@
 
 #include "evas_font_private.h" /* for Frame-Queuing support */
 #include "evas_font_ot.h"
-#include <freetype/tttables.h> /* Freetype2 OS/2 font table. */
+#include <ft2build.h>
+#include FT_TRUETYPE_TABLES_H /* Freetype2 OS/2 font table. */
 
 #ifdef EVAS_CSERVE2
 # include "../../cserve2/evas_cs2_private.h"
