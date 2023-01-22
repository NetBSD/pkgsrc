$NetBSD: patch-intern_mikktspace_mikk__float3.hh,v 1.1 2023/01/22 21:24:37 ryoon Exp $

--- intern/mikktspace/mikk_float3.hh.orig	2022-11-04 00:33:06.000000000 +0000
+++ intern/mikktspace/mikk_float3.hh
@@ -72,7 +72,7 @@ struct float3 {
 
   float length() const
   {
-    return sqrt(length_squared());
+    return sqrtf(length_squared());
   }
 
   static float distance(const float3 &a, const float3 &b)
