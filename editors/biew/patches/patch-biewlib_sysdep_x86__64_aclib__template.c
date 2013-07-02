$NetBSD: patch-biewlib_sysdep_x86__64_aclib__template.c,v 1.1 2013/07/02 12:17:30 joerg Exp $

--- biewlib/sysdep/x86_64/aclib_template.c.orig	2013-07-01 19:27:11.000000000 +0000
+++ biewlib/sysdep/x86_64/aclib_template.c
@@ -441,7 +441,7 @@ static void __FASTCALL__ RENAME(ShortsTo
 	       ::"r"(srcptr):"memory");
 	 nlimit--;
 	 __asm __volatile("packuswb (%0), %%xmm0\n\t"
-	       ::"g"(&srcptr[REGMM_SIZE]):"memory");
+	       ::"r"(&srcptr[REGMM_SIZE]):"memory");
 	 srcptr+=step*2;
 	 __asm __volatile("movdqa	%%xmm0, (%0)\n\t"
 	       ::"r"(destbuffptr):"memory");
