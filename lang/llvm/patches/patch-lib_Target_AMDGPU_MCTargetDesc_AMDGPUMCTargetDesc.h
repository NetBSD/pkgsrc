$NetBSD: patch-lib_Target_AMDGPU_MCTargetDesc_AMDGPUMCTargetDesc.h,v 1.1 2025/04/20 22:05:34 js Exp $

--- lib/Target/AMDGPU/MCTargetDesc/AMDGPUMCTargetDesc.h.orig	2025-04-20 21:12:27.871931940 +0000
+++ lib/Target/AMDGPU/MCTargetDesc/AMDGPUMCTargetDesc.h
@@ -15,6 +15,7 @@
 #ifndef LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPUMCTARGETDESC_H
 #define LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPUMCTARGETDESC_H
 
+#include <cstdint>
 #include <memory>
 
 namespace llvm {
