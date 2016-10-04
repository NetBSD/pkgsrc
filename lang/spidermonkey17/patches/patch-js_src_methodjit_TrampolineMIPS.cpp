$NetBSD: patch-js_src_methodjit_TrampolineMIPS.cpp,v 1.1 2016/10/04 02:30:46 maya Exp $

shut up linker error about not being PIC
the previous code was just an expansion of this macro

--- js/src/methodjit/TrampolineMIPS.cpp.orig	2013-02-11 22:33:23.000000000 +0000
+++ js/src/methodjit/TrampolineMIPS.cpp
@@ -107,9 +107,7 @@ asm (
     ".type  JaegerTrampoline,@function" "\n"
 "JaegerTrampoline:"     "\n"
 #if defined(__PIC__)
-    "lui    $28,%hi(_gp_disp)"  "\n"
-    "addiu  $28,$28,%lo(_gp_disp)"      "\n"
-    "addu   $28,$28,$25"    "\n"
+    ".cpload $25"  "\n"
 #endif
     "addiu  $29,$29,-112"   "\n"
     "sw     $31,104($29)"   "\n"
