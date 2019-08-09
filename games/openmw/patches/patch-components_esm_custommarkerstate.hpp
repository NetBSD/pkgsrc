$NetBSD: patch-components_esm_custommarkerstate.hpp,v 1.1 2019/08/09 16:26:09 nia Exp $

fix builds against MyGUI master

Upstream commit:
https://github.com/OpenMW/openmw/commit/698c90b3ee01bb4e8be7f8ac72ce2029bb681dae.patch

--- components/esm/custommarkerstate.hpp.orig	2019-03-10 10:50:29.000000000 +0000
+++ components/esm/custommarkerstate.hpp
@@ -16,7 +16,7 @@ struct CustomMarker
 
     std::string mNote;
 
-    bool operator == (const CustomMarker& other)
+    bool operator == (const CustomMarker& other) const
     {
         return mNote == other.mNote && mCell == other.mCell && mWorldX == other.mWorldX && mWorldY == other.mWorldY;
     }
