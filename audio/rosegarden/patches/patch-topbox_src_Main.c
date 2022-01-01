$NetBSD: patch-topbox_src_Main.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Silence compiler warnings.

--- topbox/src/Main.c~	1999-09-21 13:34:29.000000000 +0000
+++ topbox/src/Main.c
@@ -131,6 +131,10 @@ int ErrorXIO(Display *d)
 
 /* Handler for Toolkit errors, always fatal */
 
+static
+#if defined(__CLANG__) || defined(__GNUC__)
+__attribute__((__noreturn__))
+#endif
 void ErrorXt(char *msg)
 {
   Begin("ErrorXt");
