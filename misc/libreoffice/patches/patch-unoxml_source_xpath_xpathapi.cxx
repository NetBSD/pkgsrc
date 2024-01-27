$NetBSD: patch-unoxml_source_xpath_xpathapi.cxx,v 1.1 2024/01/27 22:35:07 wiz Exp $

Fix build with libxml2 2.12.

--- unoxml/source/xpath/xpathapi.cxx.orig	2024-01-27 21:40:55.769672874 +0000
+++ unoxml/source/xpath/xpathapi.cxx
@@ -217,7 +217,7 @@ namespace XPath
         return selectSingleNode(contextNode, expr);
     }
 
-    static OUString make_error_message(xmlErrorPtr pError)
+    static OUString make_error_message(const xmlError* pError)
     {
         OUStringBuffer buf;
         if (pError) {
@@ -259,7 +259,7 @@ namespace XPath
             SAL_WARN("unoxml", "libxml2 error: " << str);
         }
 
-        static void structured_error_func(void *, xmlErrorPtr error)
+        static void structured_error_func(void *, const xmlError* error)
         {
             SAL_WARN("unoxml", "libxml2 error: " << make_error_message(error));
         }
