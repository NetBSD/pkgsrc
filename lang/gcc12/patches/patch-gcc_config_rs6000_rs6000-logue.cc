--- gcc/config/rs6000/rs6000-logue.cc.orig	2024-06-20 01:08:06.000000000 -0700
+++ gcc/config/rs6000/rs6000-logue.cc	2024-12-17 15:44:35.079391555 -0800
@@ -2277,7 +2277,8 @@
     }
   else if (DEFAULT_ABI == ABI_AIX || DEFAULT_ABI == ABI_ELFv2)
     {
-#if !defined (POWERPC_LINUX) && !defined (POWERPC_FREEBSD)
+#if !defined (POWERPC_LINUX) && !defined (POWERPC_FREEBSD) \
+    && !defined(POWERPC_NETBSD)
       /* No out-of-line save/restore routines for GPRs on AIX.  */
       gcc_assert (!TARGET_AIX || (sel & SAVRES_REG) != SAVRES_GPR);
 #endif
@@ -2289,7 +2290,8 @@
 		  : ((sel & SAVRES_LR) ? "_restgpr0_" : "_restgpr1_"));
       else if ((sel & SAVRES_REG) == SAVRES_FPR)
 	{
-#if defined (POWERPC_LINUX) || defined (POWERPC_FREEBSD)
+#if defined (POWERPC_LINUX) || defined (POWERPC_FREEBSD) \
+    || defined(POWERPC_NETBSD)
 	  if ((sel & SAVRES_LR))
 	    prefix = ((sel & SAVRES_SAVE) ? "_savefpr_" : "_restfpr_");
 	  else
