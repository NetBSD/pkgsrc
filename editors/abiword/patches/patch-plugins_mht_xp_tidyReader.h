$NetBSD: patch-plugins_mht_xp_tidyReader.h,v 1.1 2017/02/20 09:35:17 wiz Exp $

--- plugins/mht/xp/tidyReader.h.orig	2013-04-07 13:53:03.000000000 +0000
+++ plugins/mht/xp/tidyReader.h
@@ -25,7 +25,7 @@
 #define TIDYREADER_H
 
 #include <tidy/tidy.h>
-#include <tidy/buffio.h>
+#include <tidy/tidybuffio.h>
 
 #include "ut_xml.h"
 
