$NetBSD: patch-ic_m68k_m68k-m68k-insns.c,v 1.1 2013/12/28 19:16:48 martin Exp $

Fix from upstream CVS: fix sequencing for tas (avoid diag assert)

--- ic/m68k/m68k-insns.c.orig	2007-08-26 00:05:02.000000000 +0200
+++ ic/m68k/m68k-insns.c	2013-12-23 13:12:54.000000000 +0100
@@ -288,6 +288,10 @@ TME_M68K_INSN(tme_m68k_tas)
 
     /* store the value read: */
     ic->tme_m68k_ireg_memx8 = value;
+
+    /* step the transfer count once for the read, and once for the write: */
+    TME_M68K_SEQUENCE_TRANSFER_STEP;
+    TME_M68K_SEQUENCE_TRANSFER_STEP;
   }
       
   /* the modify part of the read/modify/write cycle: */
