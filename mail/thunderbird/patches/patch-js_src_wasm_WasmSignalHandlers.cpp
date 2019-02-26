$NetBSD: patch-js_src_wasm_WasmSignalHandlers.cpp,v 1.2 2019/02/26 11:32:13 ryoon Exp $

--- js/src/wasm/WasmSignalHandlers.cpp.orig	2019-02-13 14:19:40.000000000 +0000
+++ js/src/wasm/WasmSignalHandlers.cpp
@@ -133,6 +133,7 @@ struct AutoSignalHandler {
 #define EBP_sig(p) ((p)->uc_mcontext.gregs[REG_EBP])
 #define ESP_sig(p) ((p)->uc_mcontext.gregs[REG_ESP])
 #else
+#include <sys/regset.h>
 #define XMM_sig(p, i) ((p)->uc_mcontext.fpregs.fp_reg_set.fpchip_state.xmm[i])
 #define EIP_sig(p) ((p)->uc_mcontext.gregs[REG_PC])
 #define EBP_sig(p) ((p)->uc_mcontext.gregs[REG_EBP])
