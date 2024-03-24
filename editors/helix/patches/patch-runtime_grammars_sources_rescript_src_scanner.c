$NetBSD: patch-runtime_grammars_sources_rescript_src_scanner.c,v 1.1 2024/03/24 20:06:49 adam Exp $

error: type specifier missing, defaults to 'int'; ISO C99 and later do not support implicit int

--- runtime/grammars/sources/rescript/src/scanner.c.orig	2024-03-24 19:39:37.013138729 +0000
+++ runtime/grammars/sources/rescript/src/scanner.c
@@ -131,7 +131,7 @@ bool tree_sitter_rescript_external_scann
     const bool* valid_symbols
     ) {
   ScannerState* state = (ScannerState*)payload;
-  const in_string = state->in_quotes || state->in_backticks;
+  const int in_string = state->in_quotes || state->in_backticks;
 
   if (valid_symbols[TEMPLATE_CHARS]) {
     lexer->result_symbol = TEMPLATE_CHARS;
