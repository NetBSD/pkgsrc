$NetBSD: patch-gcc_c-family_c-pragma.h,v 1.2 2025/06/08 07:37:45 wiz Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/c-family/c-pragma.h.orig	2025-05-23 11:02:04.248196827 +0000
+++ gcc/c-family/c-pragma.h
@@ -276,6 +276,9 @@ extern void pragma_lex_discard_to_eol ()
 #define C_LEX_STRING_NO_JOIN	  2 /* Do not concatenate strings
 				       nor translate them into execution
 				       character set.  */
+#define C_LEX_NUMBER_AS_STRING	  4 /* Do not classify a number, but
+				       instead return it as a raw
+				       string.  */
 
 /* This is not actually available to pragma parsers.  It's merely a
    convenient location to declare this function for c-lex, after
