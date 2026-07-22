$NetBSD: patch-gcc_config_rs6000_rs6000.cc,v 1.1 2026/07/22 19:28:26 he Exp $

Carry over changes from in-tree gcc in an attempt at
making this build on NetBSD/powerpc.

--- gcc/config/rs6000/rs6000.cc.orig	13 Sep 2025 23:45:31 -0000	1.1.1.4
+++ gcc/config/rs6000/rs6000.cc	14 Sep 2025 00:07:22 -0000	1.5
@@ -96,7 +96,7 @@
      of the include files, so that POWERPC_LINUX and POWERPC_FREEBSD are
      properly defined.  */
 #ifndef TARGET_IEEEQUAD_DEFAULT
-#if !defined (POWERPC_LINUX) && !defined (POWERPC_FREEBSD)
+#if !defined (POWERPC_LINUX) && !defined (POWERPC_FREEBSD) && !defined(POWERPC_NETBSD)
 #define TARGET_IEEEQUAD_DEFAULT 1
 #else
 #define TARGET_IEEEQUAD_DEFAULT 0
@@ -21230,7 +21230,11 @@
   if (flag_pic)
     return 3;
   else if (DEFAULT_ABI == ABI_AIX || DEFAULT_ABI == ABI_ELFv2)
+#if defined (POWERPC_NETBSD)
+    return 3;
+#else
     return 2;
+#endif
   else
     return 0;
 }
