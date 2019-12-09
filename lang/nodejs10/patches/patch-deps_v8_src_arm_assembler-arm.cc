$NetBSD: patch-deps_v8_src_arm_assembler-arm.cc,v 1.1 2019/12/09 20:05:40 adam Exp $

--- deps/v8/src/arm/assembler-arm.cc.orig	2018-12-26 05:26:14.000000000 +0000
+++ deps/v8/src/arm/assembler-arm.cc
@@ -343,7 +343,7 @@ Address RelocInfo::embedded_address() co
 }
 
 uint32_t RelocInfo::embedded_size() const {
-  return reinterpret_cast<uint32_t>(
+  return static_cast<uint32_t>(
       Assembler::target_address_at(pc_, constant_pool_));
 }
 
@@ -354,7 +354,7 @@ void RelocInfo::set_embedded_address(Add
 
 void RelocInfo::set_embedded_size(uint32_t size, ICacheFlushMode flush_mode) {
   Assembler::set_target_address_at(pc_, constant_pool_,
-                                   reinterpret_cast<Address>(size), flush_mode);
+                                   static_cast<Address>(size), flush_mode);
 }
 
 void RelocInfo::set_js_to_wasm_address(Address address,
