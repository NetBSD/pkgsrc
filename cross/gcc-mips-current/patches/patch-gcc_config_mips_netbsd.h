$NetBSD: patch-gcc_config_mips_netbsd.h,v 1.3 2014/07/05 09:03:49 martin Exp $

Use same types, pre-defines and link specs as the in-tree compiler.

--- gcc/config/mips/netbsd.h.orig	2014-04-01 12:40:57.000000000 +0200
+++ gcc/config/mips/netbsd.h	2014-07-05 10:37:40.000000000 +0200
@@ -32,18 +32,63 @@
       if (TARGET_ABICALLS)				\
 	builtin_define ("__ABICALLS__");		\
 							\
-      if (mips_abi == ABI_32)				\
-	builtin_define ("__mips_o32");			\
-      else if (mips_abi == ABI_EABI)			\
-	builtin_define ("__mips_eabi");			\
-      else if (mips_abi == ABI_N32)			\
+    /* The GNU C++ standard library requires this.  */		\
+    if (c_dialect_cxx ())					\
+      builtin_define ("_GNU_SOURCE");				\
+    								\
+    if (mips_abi == ABI_N32)					\
+      {								\
 	builtin_define ("__mips_n32");			\
+        builtin_define ("_ABIN32=2");				\
+        builtin_define ("_MIPS_SIM=_ABIN32");			\
+        builtin_define ("_MIPS_SZLONG=32");			\
+        builtin_define ("_MIPS_SZPTR=32");			\
+      }								\
       else if (mips_abi == ABI_64)			\
+      {								\
 	builtin_define ("__mips_n64");			\
+        builtin_define ("_ABI64=3");				\
+        builtin_define ("_MIPS_SIM=_ABI64");			\
+        builtin_define ("_MIPS_SZLONG=64");			\
+        builtin_define ("_MIPS_SZPTR=64");			\
+      }								\
       else if (mips_abi == ABI_O64)			\
+      {								\
 	builtin_define ("__mips_o64");			\
+        builtin_define ("_ABIO64=4");				\
+        builtin_define ("_MIPS_SIM=_ABIO64");			\
+        builtin_define ("_MIPS_SZLONG=64");			\
+        builtin_define ("_MIPS_SZPTR=64");			\
     }							\
-  while (0)
+    else if (mips_abi == ABI_EABI)				\
+      {								\
+	builtin_define ("__mips_eabi");				\
+        builtin_define ("_ABIEMB=5");				\
+        builtin_define ("_MIPS_SIM=_ABIEMB");			\
+	if (TARGET_LONG64)					\
+          builtin_define ("_MIPS_SZLONG=64");			\
+	else							\
+          builtin_define ("_MIPS_SZLONG=32");			\
+	if (TARGET_64BIT)					\
+          builtin_define ("_MIPS_SZPTR=64");			\
+	else							\
+          builtin_define ("_MIPS_SZPTR=32");			\
+      }								\
+    else							\
+      {								\
+	builtin_define ("__mips_o32");				\
+	builtin_define ("_ABIO32=1");				\
+	builtin_define ("_MIPS_SIM=_ABIO32");			\
+        builtin_define ("_MIPS_SZLONG=32");			\
+        builtin_define ("_MIPS_SZPTR=32");			\
+      }								\
+    if (TARGET_FLOAT64)						\
+      builtin_define ("_MIPS_FPSET=32");			\
+    else							\
+      builtin_define ("_MIPS_FPSET=16");			\
+    								\
+    builtin_define ("_MIPS_SZINT=32");				\
+  } while (0)
 
 /* The generic MIPS TARGET_CPU_CPP_BUILTINS are incorrect for NetBSD.
    Specifically, they define too many namespace-invasive macros.  Override
@@ -99,6 +144,11 @@
 	  builtin_define ("__mips=64");				\
 	  builtin_define ("__mips_isa_rev=1");			\
 	}							\
+      else if (ISA_MIPS64R2)					\
+	{							\
+	  builtin_define ("__mips=64");				\
+	  builtin_define ("__mips_isa_rev=2");			\
+	}							\
 								\
       if (TARGET_HARD_FLOAT)					\
 	builtin_define ("__mips_hard_float");			\
@@ -138,10 +188,12 @@
 
 #undef LINK_SPEC
 #define LINK_SPEC \
-  "%{EL:-m elf32lmip} \
-   %{EB:-m elf32bmip} \
+  "%{EL:-m elf32ltsmip} \
+   %{EB:-m elf32btsmip} \
    %(endian_spec) \
-   %{G*} %{mips1} %{mips2} %{mips3} %{mips4} %{mips32} %{mips32r2} %{mips64} \
+   %{G*} %{mips1} %{mips2} %{mips3} %{mips4} \
+   %{mips32} %{mips32r2} %{mips64} %{mips64r2} \
+   %{bestGnum} %{call_shared} %{no_archive} %{exact_version} \
    %(netbsd_link_spec)"
 
 #define NETBSD_ENTRY_POINT "__start"
@@ -171,6 +223,14 @@
 
 /* Make gcc agree with <machine/ansi.h> */
 
+#undef SIZE_TYPE
+#define SIZE_TYPE ((POINTER_SIZE == 64 || TARGET_NEWABI) \
+		   ? "long unsigned int" : "unsigned int")
+
+#undef PTRDIFF_TYPE
+#define PTRDIFF_TYPE ((POINTER_SIZE == 64 || TARGET_NEWABI) \
+		      ? "long int" : "int")
+
 #undef WCHAR_TYPE
 #define WCHAR_TYPE "int"
 
@@ -179,3 +239,6 @@
 
 #undef WINT_TYPE
 #define WINT_TYPE "int"
+
+#undef TARGET_WRITABLE_EH_FRAME
+#define TARGET_WRITABLE_EH_FRAME (flag_pic && TARGET_SHARED)
