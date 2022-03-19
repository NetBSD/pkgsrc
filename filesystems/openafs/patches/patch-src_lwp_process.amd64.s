$NetBSD: patch-src_lwp_process.amd64.s,v 1.1 2022/03/19 16:19:02 jakllsch Exp $

- make PIC for NetBSD/amd64 8.x; it somehow works otherwise on NetBSD 9.x

--- src/lwp/process.amd64.s.orig	2021-12-09 17:07:41.000000000 +0000
+++ src/lwp/process.amd64.s
@@ -41,7 +41,7 @@
  * just renaming the registers.
  */
 	
-#ifdef HAVE_MACHINE_ASM_H
+#if defined(__NetBSD__) || defined(HAVE_MACHINE_ASM_H)
 #include <machine/asm.h>
 #endif
 
@@ -113,7 +113,11 @@ L1:
 	jmp     *f(%rbp)                /* jump to function pointer passed in arg */
 
 /* Shouldnt be here....*/
+#if defined(__NetBSD__)
+	call	PIC_PLT(_C_LABEL(abort))
+#else
 	call    _C_LABEL(abort)
+#endif
 
 /*
  * returnto(struct savearea *area2)
@@ -157,7 +161,11 @@ ENTRY(returnto)
 	
 /* We never should get here, put in emergency brake as in i386 code */
 	pushq   $1234
+#if defined(__NetBSD__)
+	call	PIC_PLT(_C_LABEL(abort))
+#else
 	call    _C_LABEL(abort)
+#endif
 
 #if defined(__linux__) && defined(__ELF__)
 	.section .note.GNU-stack,"",%progbits
