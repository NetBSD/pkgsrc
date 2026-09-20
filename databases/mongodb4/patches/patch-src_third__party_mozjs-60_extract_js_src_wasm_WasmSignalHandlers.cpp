$NetBSD: patch-src_third__party_mozjs-60_extract_js_src_wasm_WasmSignalHandlers.cpp,v 1.1 2026/09/20 13:35:01 gdt Exp $

Fix type error objected to by gcc12, but not gcc10.

--- src/third_party/mozjs-60/extract/js/src/wasm/WasmSignalHandlers.cpp.orig	2026-08-15 12:10:22.076014483 +0000
+++ src/third_party/mozjs-60/extract/js/src/wasm/WasmSignalHandlers.cpp
@@ -189,7 +189,7 @@ struct AutoSignalHandler
 #  define R32_sig(p) ((p)->uc_mcontext.gp_regs[32])
 # endif
 #elif defined(__NetBSD__)
-# define XMM_sig(p,i) (((struct fxsave64*)(p)->uc_mcontext.__fpregs)->fx_xmm[i])
+# define XMM_sig(p,i) (((struct fxsave64*)&((p)->uc_mcontext.__fpregs))->fx_xmm[i])
 # define EIP_sig(p) ((p)->uc_mcontext.__gregs[_REG_EIP])
 # define EBP_sig(p) ((p)->uc_mcontext.__gregs[_REG_EBP])
 # define ESP_sig(p) ((p)->uc_mcontext.__gregs[_REG_ESP])
