$NetBSD: patch-libgcc_config_aarch64_aarch64-asm.h,v 1.1 2025/02/05 16:30:37 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- libgcc/config/aarch64/aarch64-asm.h
+++ libgcc/config/aarch64/aarch64-asm.h
@@ -24,8 +24,6 @@

 #include "auto-target.h"

-#define L(label) .L ## label
-
 /* Marking variant PCS symbol references is important for PLT calls
    otherwise it is for documenting the PCS in the symbol table.  */
 #ifdef HAVE_AS_VARIANT_PCS
@@ -58,12 +56,31 @@
 # define AUTIASP
 #endif

+#define PASTE2(a, b) PASTE2a(a, b)
+#define PASTE2a(a, b) a ## b
+
+#ifdef __USER_LABEL_PREFIX__
+# define ASMNAME(name) PASTE2(__USER_LABEL_PREFIX__, name)
+#else
+# define ASMNAME(name) name
+#endif
+
 #ifdef __ELF__
+#define L(label) .L ## label
 #define HIDDEN(name) .hidden name
+#define GLOBAL(name) .global name
 #define SYMBOL_SIZE(name) .size name, .-name
 #define SYMBOL_TYPE(name, _type) .type name, _type
+#elif __APPLE__
+#define L(label) L ## label
+#define HIDDEN(name) .private_extern name
+#define GLOBAL(name) .globl name
+#define SYMBOL_SIZE(name)
+#define SYMBOL_TYPE(name, _type)
 #else
+#define L(label) .L ## label
 #define HIDDEN(name)
+#define GLOBAL(name) .global name
 #define SYMBOL_SIZE(name)
 #define SYMBOL_TYPE(name, _type)
 #endif
@@ -93,16 +110,19 @@ GNU_PROPERTY (FEATURE_1_AND, BTI_FLAG|PAC_FLAG)
 # endif
 #endif

-#define ENTRY_ALIGN(name, align) \
-  .global name;		\
-  SYMBOL_TYPE(name, %function);		\
-  .balign align;	\
-  name:			\
-  .cfi_startproc;	\
-  BTI_C
-
-#define ENTRY(name) ENTRY_ALIGN(name, 16)
-
-#define END(name) \
-  .cfi_endproc;		\
-  SYMBOL_SIZE(name)
+.macro	ENTRY_ALIGNP2m, name, align
+	.text
+	.p2align \align
+	GLOBAL (\name)
+	SYMBOL_TYPE(\name, %function)
+\name:
+	.cfi_startproc
+	BTI_C
+.endm
+
+#define ENTRY(name) ENTRY_ALIGNP2m name, 4
+
+.macro	ENDm, name
+	.cfi_endproc
+	SYMBOL_SIZE (\name)
+.endm
