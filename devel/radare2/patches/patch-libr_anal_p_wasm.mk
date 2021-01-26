$NetBSD: patch-libr_anal_p_wasm.mk,v 1.2 2021/01/26 14:25:00 kamil Exp $

* Do not pass empty -I to CC/cwrappers. Avoid "Missing argument for -I".

Merged upstream:
https://github.com/radareorg/radare2/commit/de01f2d7db0508d16b0c43703bed9de3b9a78708

--- libr/anal/p/wasm.mk.orig	2019-02-19 12:35:24.000000000 +0000
+++ libr/anal/p/wasm.mk
@@ -1,5 +1,5 @@
 OBJ_WASM=anal_wasm.o
-CFLAGS+=-I$(WASM_ROOT)
+#CFLAGS+=-I$(WASM_ROOT)
 
 STATIC_OBJ+=${OBJ_WASM}
 TARGET_WASM=anal_wasm.${EXT_SO}
