$NetBSD: patch-src_core_spatialindex_include_Tools.h,v 1.1 2012/01/23 08:58:00 adam Exp $

Fix building with Clang.

--- src/core/spatialindex/include/Tools.h.orig	2011-06-07 07:42:08.000000000 +0000
+++ src/core/spatialindex/include/Tools.h
@@ -407,7 +407,7 @@ namespace Tools
     private:
       std::map<std::string, Variant> m_propertySet;
 
-#ifdef _MSC_VER
+#if defined(_MSC_VER) || defined(__clang__)
       // MSVC's friend function syntax differs slightly from everyone elses:
       // don't seem to need to qualify function name.
       friend std::ostream& operator<<(
@@ -620,7 +620,7 @@ namespace Tools
       unsigned long long* m_a;
       unsigned long m_k;
 
-#ifdef _MSC_VER
+#if defined(_MSC_VER) || defined(__clang__)
       // MSVC's friend function syntax differs slightly from everyone elses
       // don't seem to need to qualify function name.
       friend std::ostream& operator<<(
