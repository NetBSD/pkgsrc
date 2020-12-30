$NetBSD: patch-js_src_wasm_WasmSignalHandlers.cpp,v 1.1 2020/12/30 06:10:37 gutteridge Exp $

Fix SunOS/x86_64 build.

--- js/src/wasm/WasmSignalHandlers.cpp.orig	2020-11-04 10:52:03.000000000 +0000
+++ js/src/wasm/WasmSignalHandlers.cpp
@@ -115,6 +115,7 @@ using mozilla::DebugOnly;
 #    define EBP_sig(p) ((p)->uc_mcontext.gregs[REG_EBP])
 #    define ESP_sig(p) ((p)->uc_mcontext.gregs[REG_ESP])
 #  else
+#    include<sys/regset.h>
 #    define EIP_sig(p) ((p)->uc_mcontext.gregs[REG_PC])
 #    define EBP_sig(p) ((p)->uc_mcontext.gregs[REG_EBP])
 #    define ESP_sig(p) ((p)->uc_mcontext.gregs[REG_ESP])
