$NetBSD: patch-poppler_StructElement.cc,v 1.1 2017/09/20 15:21:10 jperkin Exp $

Support older clang, from Homebrew.

--- poppler/StructElement.cc.orig	2017-08-13 18:30:15.000000000 +0000
+++ poppler/StructElement.cc
@@ -248,6 +248,7 @@ struct AttributeMapEntry {
 };
 
 struct AttributeDefaults {
+  AttributeDefaults() {}; // needed to support old clang
   Object Inline  = Object(objName, "Inline");
   Object LrTb = Object(objName, "LrTb");
   Object Normal = Object(objName, "Normal");
