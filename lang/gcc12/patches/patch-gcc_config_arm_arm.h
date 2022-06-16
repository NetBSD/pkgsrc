$NetBSD: patch-gcc_config_arm_arm.h,v 1.1 2022/06/16 15:43:55 adam Exp $

--- gcc/config/arm/arm.h.orig	2021-04-08 04:56:28.057740534 -0700
+++ gcc/config/arm/arm.h	2022-01-31 21:11:39.595024008 -0800
@@ -937,6 +937,11 @@
 #define ARM_UNWIND_INFO  0
 #endif
 
+/* Overriden by config/arm/netbsd-eabi.h.  */
+#ifndef ARM_DWARF_UNWIND_TABLES
+#define ARM_DWARF_UNWIND_TABLES 0
+#endif
+
 /* Use r0 and r1 to pass exception handling information.  */
 #define EH_RETURN_DATA_REGNO(N) (((N) < 2) ? N : INVALID_REGNUM)
 
@@ -948,11 +953,19 @@
 #define ARM_TARGET2_DWARF_FORMAT DW_EH_PE_pcrel
 #endif
 
+#if ARM_DWARF_UNWIND_TABLES
+/* DWARF unwinding uses the normal indirect/pcrel vs absptr format
+   for 32bit platforms. */
+#define ASM_PREFERRED_EH_DATA_FORMAT(CODE, GLOBAL) \
+  (flag_pic ? (((GLOBAL) ? DW_EH_PE_indirect : 0) | DW_EH_PE_pcrel | DW_EH_PE_sdata4) \
+            : DW_EH_PE_absptr)
+#else
 /* ttype entries (the only interesting data references used)
    use TARGET2 relocations.  */
 #define ASM_PREFERRED_EH_DATA_FORMAT(code, data) \
   (((code) == 0 && (data) == 1 && ARM_UNWIND_INFO) ? ARM_TARGET2_DWARF_FORMAT \
 			       : DW_EH_PE_absptr)
+#endif
 
 /* The native (Norcroft) Pascal compiler for the ARM passes the static chain
    as an invisible last argument (possible since varargs don't exist in
@@ -2342,7 +2355,7 @@
 
 /* -mcpu=native handling only makes sense with compiler running on
    an ARM chip.  */
-#if defined(__arm__)
+#if defined(__arm__) && defined(__linux__)
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 #define HAVE_LOCAL_CPU_DETECT
 # define MCPU_MTUNE_NATIVE_FUNCTIONS			\
