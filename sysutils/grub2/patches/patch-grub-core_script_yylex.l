$NetBSD: patch-grub-core_script_yylex.l,v 1.1 2012/08/12 13:15:12 marino Exp $

Fix grub_script.yy.c errors:
* 'yy_fatal_error' defined but not used
* In function 'yy_scan_bytes':
  comparison between signed and unsigned integer expression 

--- grub-core/script/yylex.l.orig	2012-06-08 20:24:15.000000000 +0000
+++ grub-core/script/yylex.l
@@ -29,6 +29,7 @@
 #pragma GCC diagnostic ignored "-Wmissing-prototypes"
 #pragma GCC diagnostic ignored "-Wmissing-declarations"
 #pragma GCC diagnostic ignored "-Wunsafe-loop-optimizations"
+#pragma GCC diagnostic ignored "-Wsign-compare"
 
 #define yyfree    grub_lexer_yyfree
 #define yyalloc   grub_lexer_yyalloc
@@ -38,10 +39,6 @@
  * As we don't have access to yyscanner, we cannot do much except to
  * print the fatal error.
  */
-#define YY_FATAL_ERROR(msg)                     \
-  do {                                          \
-    grub_printf (_("fatal error: %s\n"), _(msg));     \
-  } while (0)
 
 #define COPY(str, hint)                         \
   do {                                          \
