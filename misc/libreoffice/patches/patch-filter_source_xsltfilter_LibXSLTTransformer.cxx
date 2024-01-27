$NetBSD: patch-filter_source_xsltfilter_LibXSLTTransformer.cxx,v 1.1 2024/01/27 22:35:07 wiz Exp $

Fix build with libxml2 2.12.

--- filter/source/xsltfilter/LibXSLTTransformer.cxx.orig	2024-01-27 21:33:18.356369086 +0000
+++ filter/source/xsltfilter/LibXSLTTransformer.cxx
@@ -333,7 +333,7 @@ namespace XSLT
         }
         else
         {
-            xmlErrorPtr lastErr = xmlGetLastError();
+            const xmlError* lastErr = xmlGetLastError();
             OUString msg;
             if (lastErr)
                 msg = OStringToOUString(lastErr->message, RTL_TEXTENCODING_UTF8);
