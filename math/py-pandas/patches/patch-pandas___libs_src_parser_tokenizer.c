$NetBSD: patch-pandas___libs_src_parser_tokenizer.c,v 1.2 2026/06/05 10:41:53 adam Exp $

Fix segfault in some read_csv() cases under NetBSD.

--- pandas/_libs/src/parser/tokenizer.c.orig	2026-05-11 16:18:35.000000000 +0000
+++ pandas/_libs/src/parser/tokenizer.c
@@ -634,7 +634,7 @@ static int parser_buffer_bytes(parser_t
 
 // applied when in a field
 #define IS_DELIMITER(c)                                                        \
-  ((!delim_whitespace && c == delimiter) || (delim_whitespace && isblank(c)))
+  ((!delim_whitespace && c == delimiter) || (delim_whitespace && isblank((unsigned char)c)))
 
 #define _TOKEN_CLEANUP()                                                       \
   self->stream_len = slen;                                                     \
@@ -776,7 +776,7 @@ static int tokenize_bytes(parser_t *self
         self->state = EAT_CRNL_NOP;
         break;
       } else if (!self->delim_whitespace) {
-        if (isblank(c) && c != self->delimiter) {
+        if (isblank((unsigned char)c) && c != self->delimiter) {
         } else { // backtrack
           // use i + 1 because buf has been incremented but not i
           do {
@@ -806,7 +806,7 @@ static int tokenize_bytes(parser_t *self
       } else if (IS_COMMENT_CHAR(c)) {
         self->state = EAT_COMMENT;
         break;
-      } else if (!isblank(c)) {
+      } else if (!isblank((unsigned char)c)) {
         self->state = START_FIELD;
         PD_FALLTHROUGH; // fall through to subsequent state
       } else {
@@ -850,7 +850,7 @@ static int tokenize_bytes(parser_t *self
       } else if (IS_COMMENT_CHAR(c)) {
         self->state = EAT_LINE_COMMENT;
         break;
-      } else if (isblank(c)) {
+      } else if (isblank((unsigned char)c)) {
         if (self->delim_whitespace) {
           if (self->skip_empty_lines) {
             self->state = WHITESPACE_LINE;
