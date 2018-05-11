$NetBSD: patch-js_src_wasm_WasmSignalHandlers.cpp,v 1.1 2018/05/11 19:18:35 jperkin Exp $

Support SunOS.

--- js/src/wasm/WasmSignalHandlers.cpp.orig	2018-04-28 01:04:03.000000000 +0000
+++ js/src/wasm/WasmSignalHandlers.cpp
@@ -130,11 +130,12 @@ class AutoSetHandlingSegFault
 #  define EPC_sig(p) ((p)->sc_pc)
 #  define RFP_sig(p) ((p)->sc_regs[30])
 # endif
-#elif defined(__linux__) || defined(SOLARIS)
+#elif defined(__linux__) || defined(__sun)
 # if defined(__linux__)
 #  define XMM_sig(p,i) ((p)->uc_mcontext.fpregs->_xmm[i])
 #  define EIP_sig(p) ((p)->uc_mcontext.gregs[REG_EIP])
 # else
+#  include <sys/regset.h>
 #  define XMM_sig(p,i) ((p)->uc_mcontext.fpregs.fp_reg_set.fpchip_state.xmm[i])
 #  define EIP_sig(p) ((p)->uc_mcontext.gregs[REG_PC])
 # endif
