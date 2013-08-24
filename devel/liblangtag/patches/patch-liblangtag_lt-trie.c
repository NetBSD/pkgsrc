$NetBSD: patch-liblangtag_lt-trie.c,v 1.1 2013/08/24 16:15:10 jaapb Exp $

Correct C syntax error
--- liblangtag/lt-trie.c.orig	2013-04-30 02:37:30.000000000 +0000
+++ liblangtag/lt-trie.c
@@ -33,11 +33,11 @@ struct _lt_trie_t {
 	lt_iter_tmpl_t  parent;
 	lt_trie_node_t *root;
 };
-typedef struct _lt_trie_iter_t {
+struct _lt_trie_iter_t {
 	lt_iter_t    parent;
 	lt_list_t   *stack;
 	lt_string_t *pos_str;
-} lt_trie_iter_t;
+};
 
 /*< private >*/
 static lt_trie_node_t *
