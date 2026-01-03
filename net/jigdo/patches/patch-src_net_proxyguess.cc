$NetBSD: patch-src_net_proxyguess.cc,v 1.1 2026/01/03 18:13:23 bsiegert Exp $

In C++17, a comparison function needs to be able to be called when
const-qualified.

--- src/net/proxyguess.cc.orig	2026-01-03 17:17:30.754018280 +0000
+++ src/net/proxyguess.cc
@@ -214,7 +214,7 @@ namespace {
 
   // Compare pointers to BrowserConfigs by comparing the objects' age
   struct ConfFilesCompare {
-    bool operator()(const BrowserConfig* a, const BrowserConfig* b) {
+    bool operator()(const BrowserConfig* a, const BrowserConfig* b) const {
       return a->age < b->age;
     }
   };
