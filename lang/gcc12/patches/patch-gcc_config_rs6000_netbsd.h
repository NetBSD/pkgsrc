$NetBSD: patch-gcc_config_rs6000_netbsd.h,v 1.1 2026/07/18 09:12:38 he Exp $

Carry over changes from in-tree gcc in an attempt at
making this build on NetBSD/powerpc.

In particular this should enable -msecure-plt by default so that
the compiler produces executables which will run with

   security.pax.mprotect.enabled=1

--- gcc/config/rs6000/netbsd.h.orig	2026-07-17 07:01:21.448909835 +0000
+++ gcc/config/rs6000/netbsd.h
@@ -31,6 +31,12 @@
       builtin_define ("__powerpc__");		\
       builtin_assert ("cpu=powerpc");		\
       builtin_assert ("machine=powerpc");	\
+      if (TARGET_SECURE_PLT)			\
+        builtin_define ("_SECURE_PLT");		\
+      if (TARGET_SOFT_FLOAT)			\
+        builtin_define ("_SOFT_FLOAT");		\
+      if (TARGET_ISEL)				\
+        builtin_define ("__PPC_ISEL__");	\
     }						\
   while (0)
 
@@ -62,6 +68,29 @@
 #undef  PTRDIFF_TYPE
 #define PTRDIFF_TYPE "int"
 
+/* Redefine some types that where redefined by rs6000 include files.  */
+
+#undef WCHAR_TYPE
+#define WCHAR_TYPE "int"
+
+#undef WCHAR_TYPE_SIZE
+#define WCHAR_TYPE_SIZE 32
+
+#undef WINT_TYPE
+#define WINT_TYPE "int"
+
+#undef INT64_TYPE
+#define INT64_TYPE "long long int"
+
+#undef UINT64_TYPE
+#define UINT64_TYPE "long long unsigned int"
+
+#undef INTMAX_TYPE
+#define INTMAX_TYPE "long long int"
+
+#undef UINTMAX_TYPE
+#define UINTMAX_TYPE "long long unsigned int"
+
 /* Undo the spec mess from sysv4.h, and just define the specs
    the way NetBSD systems actually expect.  */
 
@@ -79,18 +108,39 @@
 #define STARTFILE_SPEC NETBSD_STARTFILE_SPEC
 
 #undef  ENDFILE_SPEC
-#define ENDFILE_SPEC "%(netbsd_endfile_spec)"
+#define ENDFILE_SPEC NETBSD_ENDFILE_SPEC
 
 #undef  LIB_SPEC
 #define LIB_SPEC NETBSD_LIB_SPEC
 
 #undef  SUBTARGET_EXTRA_SPECS
 #define SUBTARGET_EXTRA_SPECS					\
-  { "netbsd_link_spec",		NETBSD_LINK_SPEC_ELF },		\
-  { "netbsd_entry_point",	NETBSD_ENTRY_POINT },		\
-  { "netbsd_endfile_spec",	NETBSD_ENDFILE_SPEC },
+  { "cc1_secure_plt_default",  CC1_SECURE_PLT_DEFAULT_SPEC },   \
+  NETBSD_SUBTARGET_EXTRA_SPECS
 
+/*
+ * Add NetBSD specific defaults: -mstrict-align
+ */
+#undef TARGET_DEFAULT
+#define TARGET_DEFAULT (MASK_STRICT_ALIGN)
+
+/*
+ * We know we have the right binutils for this (we shouldn't need to do this
+ * but until the cross build does the right thing...)
+ */
+#undef TARGET_SECURE_PLT
+#define TARGET_SECURE_PLT secure_plt
+#undef HAVE_AS_TLS
+#define HAVE_AS_TLS 1
+#define POWERPC_NETBSD
+
+/* Attempt to enable execute permissions on the stack.  */
+//#define TRANSFER_FROM_TRAMPOLINE NETBSD_ENABLE_EXECUTE_STACK
+// XXXMRG use enable-execute-stack-mprotect.c ?
+#ifdef L_trampoline
+#undef TRAMPOLINE_SIZE
+#define TRAMPOLINE_SIZE 48
+#endif
 
 /* Use standard DWARF numbering for DWARF debugging information.  */
 #define RS6000_USE_DWARF_NUMBERING
-
