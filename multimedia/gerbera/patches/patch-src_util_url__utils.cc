$NetBSD: patch-src_util_url__utils.cc,v 1.1 2026/06/25 08:16:54 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/util/url_utils.cc.orig	2026-06-25 08:10:22.024508085 +0000
+++ src/util/url_utils.cc
@@ -141,10 +141,10 @@ std::string urlUnescape(std::string_view str)
             char chi = data[i++];
             char clo = data[i++];
 
-            auto pos = std::strchr(hexCharS2, chi);
+            auto pos = strchr(hexCharS2, chi);
             int hi = pos ? pos - hexCharS2 : 0;
 
-            pos = std::strchr(hexCharS2, clo);
+            pos = strchr(hexCharS2, clo);
             int lo = pos ? pos - hexCharS2 : 0;
 
             int ascii = (hi << 4) | lo;
@@ -186,11 +186,11 @@ std::map<std::string, std::string> dictDecode(std::str
     const char* data = url.data();
     const char* dataEnd = data + url.length();
     while (data < dataEnd) {
-        const char* ampPos = std::strchr(data, '&');
+        const char* ampPos = strchr(data, '&');
         if (!ampPos) {
             ampPos = dataEnd;
         }
-        const char* eqPos = std::strchr(data, '=');
+        const char* eqPos = strchr(data, '=');
         if (eqPos && eqPos < ampPos) {
             auto key = std::string_view(data, eqPos - data);
             auto value = std::string_view(eqPos + 1, ampPos - eqPos - 1);
