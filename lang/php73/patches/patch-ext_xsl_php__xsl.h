$NetBSD: patch-ext_xsl_php__xsl.h,v 1.1 2018/12/15 17:12:44 taca Exp $

The dom header is now supplied by the main php bl3.

--- ext/xsl/php_xsl.h.orig	2017-03-14 13:17:46.000000000 +0000
+++ ext/xsl/php_xsl.h
@@ -41,7 +41,7 @@ extern zend_module_entry xsl_module_entr
 #include <libexslt/exsltconfig.h>
 #endif
 
-#include "../dom/xml_common.h"
+#include "dom/xml_common.h"
 #include "xsl_fe.h"
 
 #include <libxslt/extensions.h>
