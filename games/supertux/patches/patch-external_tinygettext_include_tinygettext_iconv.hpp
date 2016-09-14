$NetBSD: patch-external_tinygettext_include_tinygettext_iconv.hpp,v 1.1 2016/09/14 16:24:26 maya Exp $

Fix ICONV_CONST lack of definition.

--- external/tinygettext/include/tinygettext/iconv.hpp.orig	2015-12-20 14:56:35.000000000 +0000
+++ external/tinygettext/include/tinygettext/iconv.hpp
@@ -45,6 +45,8 @@
 #  define tinygettext_iconv_close iconv_close
 #endif
 
+#define ICONV_CONST const
+
 namespace tinygettext {
 
 class IConv
