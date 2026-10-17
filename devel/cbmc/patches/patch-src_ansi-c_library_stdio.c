$NetBSD: patch-src_ansi-c_library_stdio.c,v 1.1 2026/10/17 16:55:46 alnsn Exp $

Undefine problematic macros.

--- src/ansi-c/library/stdio.c.orig	2026-04-14 18:24:47.000000000 +0000
+++ src/ansi-c/library/stdio.c
@@ -7,7 +7,7 @@
 #endif
 
 /* undefine macros in OpenBSD's stdio.h that are problematic to the checker. */
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #undef getchar
 #undef putchar
 #undef getc
@@ -373,7 +373,11 @@ __CPROVER_HIDE:;
 __CPROVER_bool __VERIFIER_nondet___CPROVER_bool(void);
 int __VERIFIER_nondet_int(void);
 
+#if defined(__NetBSD__)
+char *__fgets_chk(char *str, int size, __CPROVER_size_t bufsize, FILE *stream)
+#else
 char *__fgets_chk(char *str, __CPROVER_size_t bufsize, int size, FILE *stream)
+#endif
 {
 __CPROVER_HIDE:;
   (void)bufsize;
