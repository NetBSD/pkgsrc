$NetBSD: patch-plugins_omelasticsearch_omelasticsearch.c,v 1.1 2015/09/21 11:15:34 wiedi Exp $

Ignore O_LARGEFILE on systems that don't have it
--- plugins/omelasticsearch/omelasticsearch.c.orig	2015-07-08 14:31:07.000000000 +0000
+++ plugins/omelasticsearch/omelasticsearch.c
@@ -49,6 +49,10 @@
 #include "cfsysline.h"
 #include "unicode-helper.h"
 
+#if !defined(O_LARGEFILE)
+#define O_LARGEFILE 0
+#endif
+
 MODULE_TYPE_OUTPUT
 MODULE_TYPE_NOKEEP
 MODULE_CNFNAME("omelasticsearch")
