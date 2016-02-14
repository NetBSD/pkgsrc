$NetBSD: patch-xpcom_reflect_xptcall_md_unix_xptcstubs__netbsd__m68k.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- xpcom/reflect/xptcall/md/unix/xptcstubs_netbsd_m68k.cpp.orig	2014-10-11 09:06:50.000000000 +0000
+++ xpcom/reflect/xptcall/md/unix/xptcstubs_netbsd_m68k.cpp
@@ -91,17 +91,27 @@ extern "C" {
     }
 }
 
+/*
+ * Beware: use % instead of %% for register identifiers in a preprocessor macro
+ * SYMBOL PREFIX must be "_" for aout and "" for ELF 
+ */
+#ifndef	__ELF__
+#define	SYMBOLPREFIX	"_"
+#else
+#define	SYMBOLPREFIX
+#endif
+
 #define STUB_ENTRY(n)							\
 __asm__(								\
-    ".global	_Stub"#n"__14nsXPTCStubBase\n\t"			\
-"_Stub"#n"__14nsXPTCStubBase:\n\t"					\
-    "link  a6,#0			\n\t"				\
-    "lea   a6@(12), a0			\n\t"	/* pointer to args */	\
-    "movl  a0, sp@-			\n\t"				\
-    "movl  #"#n", sp@-			\n\t"	/* method index */	\
-    "movl  a6@(8), sp@-			\n\t"	/* this */		\
-    "jbsr  _PrepareAndDispatch		\n\t"				\
-    "unlk  a6				\n\t"				\
+    ".global   "SYMBOLPREFIX"Stub"#n"__14nsXPTCStubBase\n\t"           \
+SYMBOLPREFIX"Stub"#n"__14nsXPTCStubBase:\n\t"                          \
+    "link  %a6,#0                      \n\t"                           \
+    "lea   %a6@(12), %a0               \n\t"   /* pointer to args */   \
+    "movl  %a0, %sp@-                  \n\t"                           \
+    "movl  #"#n", %sp@-                        \n\t"   /* method index */      \
+    "movl  %a6@(8), %sp@-              \n\t"   /* this */              \
+    "jbsr  "SYMBOLPREFIX"PrepareAndDispatch\n\t"                       \
+    "unlk  %a6                         \n\t"                           \
     "rts				\n\t"				\
 );
 
