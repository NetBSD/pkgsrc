$NetBSD: patch-src_ObjectSystem_configSymbol.hh,v 1.2 2015/12/29 23:34:51 dholland Exp $

Fix C++ build issues.

--- src/ObjectSystem/configSymbol.hh.orig	2013-11-28 00:44:18.000000000 +0000
+++ src/ObjectSystem/configSymbol.hh
@@ -50,7 +50,7 @@ public:
 private:
   struct symbolLt
   {
-    bool operator()(const Symbol* d1, const Symbol* d2)
+    bool operator()(const Symbol* d1, const Symbol* d2) const
     {
       return d1->compare(d2) < 0;
     }
