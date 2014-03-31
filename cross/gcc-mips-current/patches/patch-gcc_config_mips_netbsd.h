$NetBSD: patch-gcc_config_mips_netbsd.h,v 1.1 2014/03/31 09:49:32 martin Exp $

Define __mips_o32 for -mabi=32

--- gcc/config/mips/netbsd.h.orig	2014-01-02 23:23:26.000000000 +0100
+++ gcc/config/mips/netbsd.h	2014-03-28 14:19:18.000000000 +0100
@@ -32,7 +32,9 @@ along with GCC; see the file COPYING3.  
       if (TARGET_ABICALLS)				\
 	builtin_define ("__ABICALLS__");		\
 							\
-      if (mips_abi == ABI_EABI)				\
+      if (mips_abi == ABI_32)				\
+	builtin_define ("__mips_o32");			\
+      else if (mips_abi == ABI_EABI)			\
 	builtin_define ("__mips_eabi");			\
       else if (mips_abi == ABI_N32)			\
 	builtin_define ("__mips_n32");			\
