$NetBSD: patch-gcc_config_darwin.h,v 1.1 2025/02/05 16:30:35 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/darwin.h
+++ gcc/config/darwin.h
@@ -42,6 +42,7 @@ see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see

 #define DARWIN_X86 0
 #define DARWIN_PPC 0
+#define DARWIN_ARM64 0

 #define OBJECT_FORMAT_MACHO 1

@@ -264,6 +265,8 @@ extern GTY(()) int darwin_ms_struct;
   "%{weak_reference_mismatches*:\
     -Xlinker -weak_reference_mismatches -Xlinker %*} \
     %<weak_reference_mismatches*",					\
+  "%{weak_framework*: -Xlinker -weak_framework -Xlinker %*} \
+    %<weak_framework*",							\
   "%{whyload:-Xlinker -whyload} %<whyload",				\
   "%{whatsloaded:-Xlinker -whatsloaded} %<whatsloaded",			\
   "%{w:-Xlinker -w}",							\
@@ -371,7 +374,8 @@ extern GTY(()) int darwin_ms_struct;
 */

 #define DARWIN_NOCOMPACT_UNWIND \
-" %:version-compare(>= 10.6 mmacosx-version-min= -no_compact_unwind) "
+"%{!fuse-ld=lld: \
+    %:version-compare(>= 10.6 mmacosx-version-min= -no_compact_unwind)}"

 /* In Darwin linker specs we can put -lcrt0.o and ld will search the library
    path for crt0.o or -lcrtx.a and it will search for libcrtx.a.  As for
@@ -395,7 +399,8 @@ extern GTY(()) int darwin_ms_struct;
     LINK_PLUGIN_SPEC \
     "%{flto*:%<fcompare-debug*} \
      %{flto} %{fno-lto} %{flto=*} \
-    %l " \
+     %l \
+     %{fuse-ld=*:-fuse-ld=%*} " \
     DARWIN_PLATFORM_ID \
     LINK_COMPRESS_DEBUG_SPEC \
    "%X %{s} %{t} %{Z} %{u*} \
@@ -646,6 +651,8 @@ extern GTY(()) int darwin_ms_struct;
 #define ASM_OPTIONS "%{v} %{w:-W} %{I*}"
 #endif

+#define AS_NEEDS_DASH_FOR_PIPED_INPUT
+
 /* Default Darwin ASM_SPEC, very simple. */
 #define ASM_SPEC \
 "%{static} -arch %(darwin_arch) " \
@@ -975,7 +982,12 @@ extern GTY(()) section * darwin_sections[NUM_DARWIN_SECTIONS];
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
@@ -1223,6 +1235,10 @@ void add_framework_path (char *);
 #define TARGET_N_FORMAT_TYPES 1
 #define TARGET_FORMAT_TYPES darwin_additional_format_types

+/* We want __builtin_unreachable to be expanded as a trap instruction.  */
+#undef TARGET_UNREACHABLE_SHOULD_TRAP
+#define TARGET_UNREACHABLE_SHOULD_TRAP darwin_unreachable_traps_p
+
 #ifndef USED_FOR_TARGET
 extern void darwin_driver_init (unsigned int *,struct cl_decoded_option **);
 #define GCC_DRIVER_HOST_INITIALIZATION \
