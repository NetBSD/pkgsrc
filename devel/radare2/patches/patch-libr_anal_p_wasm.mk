$NetBSD: patch-libr_anal_p_wasm.mk,v 1.1 2019/03/26 19:30:35 ryoon Exp $

* Do not pass empty -I to CC/cwrappers. Avoid "Missing argument for -I".

--- libr/anal/p/wasm.mk.orig	2019-02-19 12:35:24.000000000 +0000
+++ libr/anal/p/wasm.mk
@@ -1,5 +1,5 @@
 OBJ_WASM=anal_wasm.o
-CFLAGS+=-I$(WASM_ROOT)
+#CFLAGS+=-I$(WASM_ROOT)
 
 STATIC_OBJ+=${OBJ_WASM}
 TARGET_WASM=anal_wasm.${EXT_SO}
