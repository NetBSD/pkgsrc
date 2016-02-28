$NetBSD: patch-src_commonmark.c,v 1.1 2016/02/28 13:33:58 kamil Exp $

Patch accepted upstream.

Fix usage of ctype(3) functions.

--- src/commonmark.c.orig	2016-01-18 05:53:29.000000000 +0000
+++ src/commonmark.c
@@ -270,8 +270,8 @@ static int S_render_node(cmark_renderer 
     // begin or end with a blank line, and code isn't
     // first thing in a list item
     if (info_len == 0 &&
-        (code_len > 2 && !isspace(code[0]) &&
-         !(isspace(code[code_len - 1]) && isspace(code[code_len - 2]))) &&
+        (code_len > 2 && !isspace((unsigned char)code[0]) &&
+         !(isspace((unsigned char)code[code_len - 1]) && isspace((unsigned char)code[code_len - 2]))) &&
         !(node->prev == NULL && node->parent &&
           node->parent->type == CMARK_NODE_ITEM)) {
       LIT("    ");
