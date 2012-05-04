$NetBSD: patch-speech__tools_include_ling__class_EST__FeatureFunctionPackage.h,v 1.1 2012/05/04 16:01:04 joerg Exp $

--- speech_tools/include/ling_class/EST_FeatureFunctionPackage.h.orig	2012-04-27 12:41:31.000000000 +0000
+++ speech_tools/include/ling_class/EST_FeatureFunctionPackage.h
@@ -70,5 +70,7 @@ public:
 };
 
 int operator == (const EST_FeatureFunctionPackage::Entry &a, const EST_FeatureFunctionPackage::Entry &b);
+ostream &operator << (ostream &s, EST_FeatureFunctionPackage::Entry &e);
+
 #endif
 
