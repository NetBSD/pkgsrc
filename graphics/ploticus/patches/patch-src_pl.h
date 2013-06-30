$NetBSD: patch-src_pl.h,v 1.1 2013/06/30 15:13:09 ryoon Exp $

* Hardcode PREFABS_DIR.

--- src/pl.h.orig	2013-05-14 20:21:14.000000000 +0000
+++ src/pl.h
@@ -8,7 +8,7 @@
 #include <stdlib.h>
 #include "plg.h"
 
-#define PREFABS_DIR ""  	 /* INSTALLERS can set this to a valid pathname, so that users don't need to set PLOTICUS_PREFABS env var */
+#define PREFABS_DIR "@PREFIX@/share/ploticus"  	 /* INSTALLERS can set this to a valid pathname, so that users don't need to set PLOTICUS_PREFABS env var */
 
 #define PLVERSION "2.42-May2013" /* see also the Copyright page, and page headers and footers */
 
