$NetBSD: patch-src_iso19111_coordinatesystem.cpp,v 1.1 2025/07/03 17:39:44 gdt Exp $

Fix ctype abuse.

Not yet filed upstream.

--- src/iso19111/coordinatesystem.cpp.orig	2025-07-03 13:25:01.929435443 +0000
+++ src/iso19111/coordinatesystem.cpp
@@ -402,7 +402,7 @@ void CoordinateSystemAxis::_exportToWKT(
     if (!axisName.empty()) {
         if (isWKT2) {
             axisDesignation =
-                tolower(axisName.substr(0, 1)) + axisName.substr(1);
+                internal::tolower(axisName.substr(0, 1)) + axisName.substr(1);
         } else {
             if (axisName == "Geodetic latitude") {
                 axisDesignation = "Latitude";
@@ -1423,7 +1423,7 @@ ParametricCS::create(const util::Propert
 // ---------------------------------------------------------------------------
 
 AxisDirection::AxisDirection(const std::string &nameIn) : CodeList(nameIn) {
-    auto lowerName = tolower(nameIn);
+    auto lowerName = internal::tolower(nameIn);
     assert(registry.find(lowerName) == registry.end());
     registry[lowerName] = this;
 }
@@ -1443,7 +1443,7 @@ AxisDirection::valueOf(const std::string
 // ---------------------------------------------------------------------------
 
 RangeMeaning::RangeMeaning(const std::string &nameIn) : CodeList(nameIn) {
-    auto lowerName = tolower(nameIn);
+    auto lowerName = internal::tolower(nameIn);
     assert(registry.find(lowerName) == registry.end());
     registry[lowerName] = this;
 }
@@ -1456,7 +1456,7 @@ RangeMeaning::RangeMeaning() : CodeList(
 
 //! @cond Doxygen_Suppress
 const RangeMeaning *RangeMeaning::valueOf(const std::string &nameIn) noexcept {
-    auto iter = registry.find(tolower(nameIn));
+    auto iter = registry.find(internal::tolower(nameIn));
     if (iter == registry.end())
         return nullptr;
     return iter->second;
@@ -1468,7 +1468,7 @@ const RangeMeaning *RangeMeaning::valueO
 
 AxisDirectionWKT1::AxisDirectionWKT1(const std::string &nameIn)
     : CodeList(nameIn) {
-    auto lowerName = tolower(nameIn);
+    auto lowerName = internal::tolower(nameIn);
     assert(registry.find(lowerName) == registry.end());
     registry[lowerName] = this;
 }
@@ -1476,7 +1476,7 @@ AxisDirectionWKT1::AxisDirectionWKT1(con
 // ---------------------------------------------------------------------------
 
 const AxisDirectionWKT1 *AxisDirectionWKT1::valueOf(const std::string &nameIn) {
-    auto iter = registry.find(tolower(nameIn));
+    auto iter = registry.find(internal::tolower(nameIn));
     if (iter == registry.end())
         return nullptr;
     return iter->second;
