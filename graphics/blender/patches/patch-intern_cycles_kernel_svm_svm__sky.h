$NetBSD: patch-intern_cycles_kernel_svm_svm__sky.h,v 1.1 2020/09/05 11:40:58 ryoon Exp $

--- intern/cycles/kernel/svm/svm_sky.h.orig	2020-08-31 11:59:44.000000000 +0000
+++ intern/cycles/kernel/svm/svm_sky.h
@@ -124,7 +124,7 @@ ccl_device float3 sky_radiance_hosek(Ker
 /* Nishita improved sky model */
 ccl_device float3 geographical_to_direction(float lat, float lon)
 {
-  return make_float3(cos(lat) * cos(lon), cos(lat) * sin(lon), sin(lat));
+  return make_float3(cosf(lat) * cosf(lon), cosf(lat) * sinf(lon), sinf(lat));
 }
 
 ccl_device float3 sky_radiance_nishita(KernelGlobals *kg,
