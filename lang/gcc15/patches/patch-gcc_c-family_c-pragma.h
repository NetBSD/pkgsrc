$NetBSD: patch-gcc_c-family_c-pragma.h,v 1.1 2026/07/19 11:17:42 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/c-family/c-pragma.h.orig	2026-06-12 06:09:06.074517522 +0000
+++ gcc/c-family/c-pragma.h
@@ -289,6 +289,9 @@ extern void pragma_lex_discard_to_eol ()
 #define C_LEX_STRING_NO_JOIN	  2 /* Do not concatenate strings
 				       nor translate them into execution
 				       character set.  */
+#define C_LEX_NUMBER_AS_STRING	  4 /* Do not classify a number, but
+				       instead return it as a raw
+				       string.  */

 /* This is not actually available to pragma parsers.  It's merely a
    convenient location to declare this function for c-lex, after
