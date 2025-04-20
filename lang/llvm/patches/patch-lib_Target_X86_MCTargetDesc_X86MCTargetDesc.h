$NetBSD: patch-lib_Target_X86_MCTargetDesc_X86MCTargetDesc.h,v 1.1 2025/04/20 22:05:34 js Exp $

--- lib/Target/X86/MCTargetDesc/X86MCTargetDesc.h.orig	2025-04-20 21:09:06.105203629 +0000
+++ lib/Target/X86/MCTargetDesc/X86MCTargetDesc.h
@@ -13,6 +13,7 @@
 #ifndef LLVM_LIB_TARGET_X86_MCTARGETDESC_X86MCTARGETDESC_H
 #define LLVM_LIB_TARGET_X86_MCTARGETDESC_X86MCTARGETDESC_H
 
+#include <cstdint>
 #include <memory>
 #include <string>
 
