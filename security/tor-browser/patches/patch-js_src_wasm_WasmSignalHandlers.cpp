$NetBSD: patch-js_src_wasm_WasmSignalHandlers.cpp,v 1.1 2019/02/25 15:32:24 wiz Exp $

Support SunOS.

--- js/src/wasm/WasmSignalHandlers.cpp.orig	2019-02-23 20:00:48.000000000 +0000
+++ js/src/wasm/WasmSignalHandlers.cpp
@@ -135,6 +135,7 @@ struct AutoSignalHandler {
 #else
 #define XMM_sig(p, i) ((p)->uc_mcontext.fpregs.fp_reg_set.fpchip_state.xmm[i])
 #define EIP_sig(p) ((p)->uc_mcontext.gregs[REG_PC])
+#  include <sys/regset.h>
 #define EBP_sig(p) ((p)->uc_mcontext.gregs[REG_EBP])
 #define ESP_sig(p) ((p)->uc_mcontext.gregs[REG_ESP])
 #endif
