$NetBSD: patch-gcc_config_arm_netbsd-elf.h,v 1.1 2018/06/17 19:50:52 maya Exp $

netbsd/arm EABI support

--- gcc/config/arm/netbsd-elf.h.orig	2017-01-01 12:07:43.000000000 +0000
+++ gcc/config/arm/netbsd-elf.h
@@ -27,9 +27,20 @@
 
 /* arm.h defaults to ARM6 CPU.  */
 
-/* This defaults us to little-endian.  */
-#ifndef TARGET_ENDIAN_DEFAULT
-#define TARGET_ENDIAN_DEFAULT 0
+/* Default EABI to armv5t so that thumb shared libraries work.
+   The ARM926EH-S core is the default for armv5te, so set
+   SUBTARGET_CPU_DEFAULT to achieve this.  */
+
+#define SUBTARGET_CPU_DEFAULT \
+	(ARM_DEFAULT_ABI != ARM_ABI_APCS && ARM_DEFAULT_ABI != ARM_ABI_ATPCS \
+	    ? TARGET_CPU_arm926ejs : TARGET_CPU_arm6)
+
+/* TARGET_BIG_ENDIAN_DEFAULT is set in
+   config.gcc for big endian configurations.  */
+#if TARGET_BIG_ENDIAN_DEFAULT
+#define TARGET_ENDIAN_DEFAULT    MASK_BIG_END
+#else
+#define TARGET_ENDIAN_DEFAULT    0
 #endif
 
 #undef MULTILIB_DEFAULTS
@@ -43,6 +54,7 @@
 #undef ARM_DEFAULT_ABI
 #define ARM_DEFAULT_ABI ARM_ABI_ATPCS
 
+#undef TARGET_OS_CPP_BUILTINS
 #define TARGET_OS_CPP_BUILTINS()	\
   do					\
     {					\
@@ -55,25 +67,21 @@
 
 #undef SUBTARGET_EXTRA_ASM_SPEC
 #define SUBTARGET_EXTRA_ASM_SPEC	\
-  "-matpcs %{" FPIE_OR_FPIC_SPEC ":-k}"
+  "-matpcs %{mabi=aapcs*:-meabi=5} %{" FPIE_OR_FPIC_SPEC ":-k}"
 
 /* Default to full VFP if -mfloat-abi=hard is specified.  */
 #undef SUBTARGET_ASM_FLOAT_SPEC
 #define SUBTARGET_ASM_FLOAT_SPEC	\
-  "%{mfloat-abi=hard:{!mfpu=*:-mfpu=vfp}}"
-
-#undef SUBTARGET_EXTRA_SPECS
-#define SUBTARGET_EXTRA_SPECS				\
-  { "subtarget_extra_asm_spec",	SUBTARGET_EXTRA_ASM_SPEC }, \
-  { "subtarget_asm_float_spec", SUBTARGET_ASM_FLOAT_SPEC }, \
-  { "netbsd_link_spec",		NETBSD_LINK_SPEC_ELF },	\
-  { "netbsd_entry_point",	NETBSD_ENTRY_POINT },
+  "%{mhard-float:%{!mfpu=*:-mfpu=vfp}}   \
+   %{mfloat-abi=hard:%{!mfpu=*:-mfpu=vfp}}"
 
 #define NETBSD_ENTRY_POINT "__start"
 
 #undef LINK_SPEC
 #define LINK_SPEC \
-  "-X %{mbig-endian:-EB} %{mlittle-endian:-EL} \
+  "-X \
+   %{mbig-endian:-EB %{-mabi=aapcs*:-m armelfb_nbsd_eabi}} \
+   %{mlittle-endian:-EL %{-mabi=aapcs*:-m armelf_nbsd_eabi}} \
    %(netbsd_link_spec)"
 
 /* Make GCC agree with <machine/ansi.h>.  */
@@ -84,6 +92,12 @@
 #undef PTRDIFF_TYPE
 #define PTRDIFF_TYPE "long int"
 
+#undef INTPTR_TYPE
+#define INTPTR_TYPE PTRDIFF_TYPE
+
+#undef UINTPTR_TYPE
+#define UINTPTR_TYPE SIZE_TYPE
+
 /* We don't have any limit on the length as out debugger is GDB.  */
 #undef DBX_CONTIN_LENGTH
 
@@ -157,3 +171,12 @@ while (0)
 #undef FPUTYPE_DEFAULT
 #define FPUTYPE_DEFAULT "vfp"
 
+/* Ensure that libgcc does not attempt to define __[CD]TOR_LIST__[] for APCS,
+   which belongs in crtbegin on NetBSD.  */
+#ifndef __ARM_EABI__
+#define CTOR_LISTS_DEFINED_EXTERNALLY
+#endif
+
+#undef FPUTYPE_DEFAULT
+#define FPUTYPE_DEFAULT "vfp"
+
