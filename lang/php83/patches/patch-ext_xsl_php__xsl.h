$NetBSD: patch-ext_xsl_php__xsl.h,v 1.1 2023/11/30 16:14:50 taca Exp $

Fix build on pkgsrc environment.

--- ext/xsl/php_xsl.h.orig	2021-03-02 16:37:06.000000000 +0000
+++ ext/xsl/php_xsl.h
@@ -37,7 +37,7 @@ extern zend_module_entry xsl_module_entr
 #include <libexslt/exsltconfig.h>
 #endif
 
-#include "../dom/xml_common.h"
+#include "dom/xml_common.h"
 
 #include <libxslt/extensions.h>
 #include <libxml/xpathInternals.h>
