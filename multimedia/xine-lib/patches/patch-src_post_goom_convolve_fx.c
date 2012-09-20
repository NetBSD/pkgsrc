$NetBSD: patch-src_post_goom_convolve_fx.c,v 1.1 2012/09/20 15:33:40 jperkin Exp $

Solaris cannot handle this MMX section, failing with:

 error: can't find a register in class GENERAL_REGS while reloading 'asm'.

--- src/post/goom/convolve_fx.c.orig	2012-09-20 15:19:11.848384461 +0000
+++ src/post/goom/convolve_fx.c	2012-09-20 15:19:24.654150136 +0000
@@ -151,7 +151,7 @@
     ytex = yprime + yi + CONV_MOTIF_W * 0x10000 / 2;
     yprime += c;
 
-#if defined(HAVE_MMX) && ! defined(ARCH_X86_64)
+#if defined(HAVE_MMX) && ! defined(ARCH_X86_64) && !defined(__sun)
 /* This code uses 32-bit registers eax,ecx,esi */
     __asm__ __volatile__
       ("\n\t pxor  %%mm7,  %%mm7"  /* mm7 = 0   */
