$NetBSD: patch-libxorp_trie.hh,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- libxorp/trie.hh.orig	2009-01-05 18:30:58.000000000 +0000
+++ libxorp/trie.hh
@@ -277,6 +277,7 @@ private:
 
     void dump(const char *msg) const
     {
+	(void)msg;
 	trie_debug_msg(" %s %s %s\n",
 		       msg,
 		       _k.str().c_str(), _p ? "PL" : "[]");
