$NetBSD: patch-gcc_config_mips_netbsd.h,v 1.1.2.2 2017/06/21 18:53:33 bsiegert Exp $

n32 support for netbsd/mips64

--- ../gcc-4.1.2/gcc/config/mips/netbsd.h.orig	2005-06-25 01:22:41.000000000 +0000
+++ ../gcc-4.1.2/gcc/config/mips/netbsd.h
@@ -39,18 +39,56 @@ Boston, MA 02110-1301, USA.  */
 	builtin_define ("__LONG64");			\
 							\
       if (TARGET_ABICALLS)				\
-	builtin_define ("__ABICALLS__");		\
+	builtin_define ("__mips_abicalls");		\
 							\
-      if (mips_abi == ABI_EABI)				\
-	builtin_define ("__mips_eabi");			\
-      else if (mips_abi == ABI_N32)			\
-	builtin_define ("__mips_n32");			\
+    if (mips_abi == ABI_N32)				\
+      {							\
+        builtin_define ("_ABIN32=2");			\
+        builtin_define ("_MIPS_SIM=_ABIN32");		\
+        builtin_define ("_MIPS_SZLONG=32");		\
+        builtin_define ("_MIPS_SZPTR=32");		\
+      }							\
       else if (mips_abi == ABI_64)			\
-	builtin_define ("__mips_n64");			\
+      {							\
+        builtin_define ("_ABI64=3");			\
+        builtin_define ("_MIPS_SIM=_ABI64");		\
+        builtin_define ("_MIPS_SZLONG=64");		\
+        builtin_define ("_MIPS_SZPTR=64");		\
+      }							\
       else if (mips_abi == ABI_O64)			\
-	builtin_define ("__mips_o64");			\
+      {							\
+        builtin_define ("_ABIO64=4");			\
+        builtin_define ("_MIPS_SIM=_ABIO64");		\
+        builtin_define ("_MIPS_SZLONG=64");		\
+        builtin_define ("_MIPS_SZPTR=64");		\
     }							\
-  while (0)
+    else if (mips_abi == ABI_EABI)			\
+      {							\
+        builtin_define ("_ABIEMB=5");			\
+        builtin_define ("_MIPS_SIM=_ABIEMB");		\
+	if (TARGET_LONG64)				\
+          builtin_define ("_MIPS_SZLONG=64");		\
+	else						\
+          builtin_define ("_MIPS_SZLONG=32");		\
+	if (TARGET_64BIT)				\
+          builtin_define ("_MIPS_SZPTR=64");		\
+	else						\
+          builtin_define ("_MIPS_SZPTR=32");		\
+      }							\
+    else						\
+      {							\
+	builtin_define ("_ABIO32=1");			\
+	builtin_define ("_MIPS_SIM=_ABIO32");		\
+        builtin_define ("_MIPS_SZLONG=32");		\
+        builtin_define ("_MIPS_SZPTR=32");		\
+      }							\
+    if (TARGET_FLOAT64)					\
+      builtin_define ("_MIPS_FPSET=32");		\
+    else						\
+      builtin_define ("_MIPS_FPSET=16");		\
+    							\
+    builtin_define ("_MIPS_SZINT=32");			\
+  } while (0)
 
 /* The generic MIPS TARGET_CPU_CPP_BUILTINS are incorrect for NetBSD.
    Specifically, they define too many namespace-invasive macros.  Override
