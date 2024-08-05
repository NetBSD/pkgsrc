$NetBSD: patch-include_llvm_Support_Signals.h,v 1.1 2024/08/05 14:04:06 tnn Exp $

Include cstdint for uintptr_t. Already fixed in upstream.

--- include/llvm/Support/Signals.h.orig	2022-01-20 21:31:59.000000000 +0000
+++ include/llvm/Support/Signals.h
@@ -15,6 +15,7 @@
 #define LLVM_SUPPORT_SIGNALS_H
 
 #include <string>
+#include <cstdint>
 
 namespace llvm {
 class StringRef;
