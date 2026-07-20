$NetBSD: patch-gcc_config_rs6000_rs6000-logue.cc,v 1.1 2026/07/20 08:02:51 he Exp $

Carry over changes from in-tree gcc in an attempt at
making this build on NetBSD/powerpc.

--- gcc/config/rs6000/rs6000-logue.cc.orig	13 Sep 2025 23:45:31 -0000	1.1.1.3
+++ gcc/config/rs6000/rs6000-logue.cc	14 Sep 2025 00:07:22 -0000	1.4
@@ -2263,7 +2263,8 @@
     }
   else if (DEFAULT_ABI == ABI_AIX || DEFAULT_ABI == ABI_ELFv2)
     {
-#if !defined (POWERPC_LINUX) && !defined (POWERPC_FREEBSD)
+#if !defined (POWERPC_LINUX) && !defined (POWERPC_FREEBSD) \
+    && !defined(POWERPC_NETBSD)
       /* No out-of-line save/restore routines for GPRs on AIX.  */
       gcc_assert (!TARGET_AIX || (sel & SAVRES_REG) != SAVRES_GPR);
 #endif
@@ -2275,7 +2276,8 @@
 		  : ((sel & SAVRES_LR) ? "_restgpr0_" : "_restgpr1_"));
       else if ((sel & SAVRES_REG) == SAVRES_FPR)
 	{
-#if defined (POWERPC_LINUX) || defined (POWERPC_FREEBSD)
+#if defined (POWERPC_LINUX) || defined (POWERPC_FREEBSD) \
+    || defined(POWERPC_NETBSD)
 	  if ((sel & SAVRES_LR))
 	    prefix = ((sel & SAVRES_SAVE) ? "_savefpr_" : "_restfpr_");
 	  else
