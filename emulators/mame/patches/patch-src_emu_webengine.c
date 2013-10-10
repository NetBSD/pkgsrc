$NetBSD: patch-src_emu_webengine.c,v 1.1 2013/10/10 00:06:19 joerg Exp $

--- src/emu/webengine.c.orig	2013-10-09 11:04:31.000000000 +0000
+++ src/emu/webengine.c
@@ -37,12 +37,12 @@
 
 ***************************************************************************/
 
+#include "web/json/json.h"
 #include "emu.h"
 #include "emuopts.h"
 #include "ui.h"
 #include "webengine.h"
 #include "web/mongoose.h"
-#include "web/json/json.h"
 
 //**************************************************************************
 //  WEB ENGINE
