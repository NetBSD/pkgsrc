$NetBSD: patch-gcc_config_arm_netbsd-eabi.h,v 1.1 2022/02/02 22:07:28 mrg Exp $

--- gcc/config/arm/netbsd-eabi.h.orig	2021-04-08 04:56:28.065740630 -0700
+++ gcc/config/arm/netbsd-eabi.h	2022-01-31 21:15:29.555403989 -0800
@@ -49,8 +49,8 @@
 
 #undef ARM_UNWIND_INFO
 #define ARM_UNWIND_INFO 0
-#undef DWARF2_UNWIND_INFO
-#define DWARF2_UNWIND_INFO 1
+#undef ARM_DWARF_UNWIND_TABLES
+#define ARM_DWARF_UNWIND_TABLES 1
 
 #undef TARGET_OS_CPP_BUILTINS
 #define TARGET_OS_CPP_BUILTINS()		\
@@ -59,7 +59,7 @@
       if (TARGET_AAPCS_BASED)			\
 	TARGET_BPABI_CPP_BUILTINS();		\
       NETBSD_OS_CPP_BUILTINS_ELF();		\
-      if (DWARF2_UNWIND_INFO)			\
+      if (ARM_DWARF_UNWIND_TABLES)		\
 	builtin_define ("__ARM_DWARF_EH__");	\
     }						\
   while (0)
@@ -81,17 +81,25 @@
 
 #undef SUBTARGET_EXTRA_ASM_SPEC
 #define SUBTARGET_EXTRA_ASM_SPEC		\
-  "%{mabi=apcs-gnu|mabi=atpcs:-meabi=gnu} "	\
+  "-matpcs %{mabi=apcs-gnu|mabi=atpcs:-meabi=gnu} "	\
   "%{fpic|fpie:-k} "				\
   "%{fPIC|fPIE:-k}"
 
+/* Default to full VFP if -mhard-float is specified.  */
+#undef SUBTARGET_ASM_FLOAT_SPEC
+#define SUBTARGET_ASM_FLOAT_SPEC	\
+  "%{mhard-float:%{!mfpu=*:-mfpu=vfp}}   \
+   %{mfloat-abi=hard:%{!mfpu=*:-mfpu=vfp}}"
+
 #undef SUBTARGET_EXTRA_SPECS
 #define SUBTARGET_EXTRA_SPECS						\
   { "subtarget_extra_asm_spec",	SUBTARGET_EXTRA_ASM_SPEC },		\
+  { "subtarget_asm_float_spec", SUBTARGET_ASM_FLOAT_SPEC }, 		\
   { "linker_eabi_suffix",	TARGET_LINKER_EABI_SUFFIX },		\
   { "linker_emulation",		TARGET_LINKER_EMULATION },		\
   { "linker_big_emulation",	TARGET_LINKER_BIG_EMULATION },		\
   { "linker_little_emulation",	TARGET_LINKER_LITTLE_EMULATION },	\
+  { "be8_link_spec",		BE8_LINK_SPEC }, 			\
   { "target_fix_v4bx_spec",	TARGET_FIX_V4BX_SPEC },			\
   NETBSD_SUBTARGET_EXTRA_SPECS
 
@@ -102,4 +110,5 @@
   "-X %{mbig-endian:-EB -m %(linker_big_emulation)} "		\
   "%{mlittle-endian:-EL -m %(linker_liitle_emulation)} "	\
   "%{!mbig-endian:%{!mlittle-endian:-m %(linker_emulation)}} "	\
+  "%(be8_link_spec) "						\
   "%(target_fix_v4bx_spec) %(netbsd_link_spec)"
