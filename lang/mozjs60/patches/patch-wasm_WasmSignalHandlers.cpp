$NetBSD: patch-wasm_WasmSignalHandlers.cpp,v 1.1 2020/04/09 09:40:47 jperkin Exp $

Fix build on SunOS/x86_64.

--- wasm/WasmSignalHandlers.cpp.orig	2019-07-01 09:07:44.000000000 +0000
+++ wasm/WasmSignalHandlers.cpp
@@ -138,6 +138,7 @@ struct AutoSignalHandler {
 #define EBP_sig(p) ((p)->uc_mcontext.gregs[REG_EBP])
 #define ESP_sig(p) ((p)->uc_mcontext.gregs[REG_ESP])
 #else
+#include <sys/regset.h>
 #define XMM_sig(p, i) ((p)->uc_mcontext.fpregs.fp_reg_set.fpchip_state.xmm[i])
 #define EIP_sig(p) ((p)->uc_mcontext.gregs[REG_PC])
 #define EBP_sig(p) ((p)->uc_mcontext.gregs[REG_EBP])
