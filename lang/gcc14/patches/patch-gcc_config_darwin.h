$NetBSD: patch-gcc_config_darwin.h,v 1.2 2025/06/08 07:37:45 wiz Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/darwin.h.orig	2025-05-23 11:02:04.332198151 +0000
+++ gcc/config/darwin.h
@@ -42,6 +42,7 @@ see the files COPYING3 and COPYING.RUNTI
 
 #define DARWIN_X86 0
 #define DARWIN_PPC 0
+#define DARWIN_ARM64 0
 
 #define OBJECT_FORMAT_MACHO 1
 
@@ -266,6 +267,8 @@ extern GTY(()) int darwin_ms_struct;
     %<weak_reference_mismatches*",					\
   "%{weak_framework*: -Xlinker -weak_framework -Xlinker %*} \
     %<weak_framework*",							\
+  "%{weak_framework*: -Xlinker -weak_framework -Xlinker %*} \
+    %<weak_framework*",							\
   "%{whyload:-Xlinker -whyload} %<whyload",				\
   "%{whatsloaded:-Xlinker -whatsloaded} %<whatsloaded",			\
   "%{w:-Xlinker -w}",							\
@@ -378,7 +381,8 @@ extern GTY(()) int darwin_ms_struct;
 */
 
 #define DARWIN_NOCOMPACT_UNWIND \
-" %:version-compare(>= 10.6 mmacosx-version-min= -no_compact_unwind) "
+"%{!fuse-ld=lld: \
+    %:version-compare(>= 10.6 mmacosx-version-min= -no_compact_unwind)}"
 
 /* In Darwin linker specs we can put -lcrt0.o and ld will search the library
    path for crt0.o or -lcrtx.a and it will search for libcrtx.a.  As for
@@ -402,7 +406,8 @@ extern GTY(()) int darwin_ms_struct;
     LINK_PLUGIN_SPEC \
     "%{flto*:%<fcompare-debug*} \
      %{flto} %{fno-lto} %{flto=*} \
-    %l " \
+     %l \
+     %{fuse-ld=*:-fuse-ld=%*} " \
     DARWIN_PLATFORM_ID \
     LINK_COMPRESS_DEBUG_SPEC \
    "%X %{s} %{t} %{Z} %{u*} \
@@ -655,6 +660,8 @@ extern GTY(()) int darwin_ms_struct;
 
 #define AS_NEEDS_DASH_FOR_PIPED_INPUT
 
+#define AS_NEEDS_DASH_FOR_PIPED_INPUT
+
 /* Default Darwin ASM_SPEC, very simple. */
 #define ASM_SPEC \
 "%{static} -arch %(darwin_arch) " \
@@ -984,7 +991,12 @@ extern GTY(()) section * darwin_sections
   { "apple_kext_compatibility", 0, 0, false, true, false, false,	     \
     darwin_handle_kext_attribute, NULL },				     \
   { "weak_import", 0, 0, true, false, false, false,			     \
-    darwin_handle_weak_import_attribute, NULL }
+    darwin_handle_weak_import_attribute, NULL },			     \
+  { "availability", 0, -1, true, false, false, false,			     \
+    darwin_handle_availability_attribute, NULL }
+
+#undef TARGET_ATTRIBUTE_TAKES_IDENTIFIER_P
+#define TARGET_ATTRIBUTE_TAKES_IDENTIFIER_P darwin_attribute_takes_identifier_p
 
 /* Make local constant labels linker-visible, so that if one follows a
    weak_global constant, ld64 will be able to separate the atoms.  */
@@ -1232,6 +1244,10 @@ void add_framework_path (char *);
 #define TARGET_N_FORMAT_TYPES 1
 #define TARGET_FORMAT_TYPES darwin_additional_format_types
 
+/* We want __builtin_unreachable to be expanded as a trap instruction.  */
+#undef TARGET_UNREACHABLE_SHOULD_TRAP
+#define TARGET_UNREACHABLE_SHOULD_TRAP darwin_unreachable_traps_p
+
 #ifndef USED_FOR_TARGET
 extern void darwin_driver_init (unsigned int *,struct cl_decoded_option **);
 #define GCC_DRIVER_HOST_INITIALIZATION \
