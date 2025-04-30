$NetBSD: patch-lib_Target_AMDGPU_MCTargetDesc_AMDGPUMCTargetDesc.h,v 1.1 2025/04/30 13:52:04 tnn Exp $

Include <cstdint> for uint8_t.

--- lib/Target/AMDGPU/MCTargetDesc/AMDGPUMCTargetDesc.h.orig	2025-04-30 11:05:42.755814590 +0000
+++ lib/Target/AMDGPU/MCTargetDesc/AMDGPUMCTargetDesc.h
@@ -15,6 +15,7 @@
 #ifndef LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPUMCTARGETDESC_H
 #define LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPUMCTARGETDESC_H
 
+#include <cstdint>
 #include <memory>
 
 namespace llvm {
