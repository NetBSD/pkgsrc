$NetBSD: patch-libr_anal_p_pyc.mk,v 1.1 2021/01/26 14:25:00 kamil Exp $

Avoid passing empty -I.

Merged upstream:
https://github.com/radareorg/radare2/commit/de01f2d7db0508d16b0c43703bed9de3b9a78708

--- libr/anal/p/pyc.mk.orig	2021-01-25 14:41:12.000000000 +0000
+++ libr/anal/p/pyc.mk
@@ -35,6 +35,7 @@ STATIC_OBJ+=${OBJ_PYC}
 TARGET_PYC=anal_pyc.$(EXT_SO)
 
 ALL_TARGETS+=${TARGET_PYC}
+PYC_ROOT=../asm/arch/pyc
 CFLAGS+=-I$(PYC_ROOT)
 
 ${TARGET_PYC}: ${OBJ_PYC}
