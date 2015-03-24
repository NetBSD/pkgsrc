$NetBSD: patch-ffmpeg_libavcodec_arm_asm.S,v 1.1 2015/03/24 14:27:20 joerg Exp $

--- ffmpeg/libavcodec/arm/asm.S.orig	2015-03-23 19:38:11.000000000 +0000
+++ ffmpeg/libavcodec/arm/asm.S
@@ -64,7 +64,11 @@ ELF     .eabi_attribute 25, \val
 .macro  function name, export=0
     .macro endfunc
 ELF     .size   \name, . - \name
+#ifdef __ARM_DWARF_EH__
+        .cfi_endproc
+#else
         .endfunc
+#endif
         .purgem endfunc
     .endm
         .text
@@ -72,10 +76,15 @@ ELF     .size   \name, . - \name
     .if \export
         .global EXTERN_ASM\name
 EXTERN_ASM\name:
+    .else
+\name:
     .endif
 ELF     .type   \name, %function
+#ifdef __ARM_DWARF_EH__
+        .cfi_startproc
+#else
         .func   \name
-\name:
+#endif
 .endm
 
 .macro  const   name, align=2
