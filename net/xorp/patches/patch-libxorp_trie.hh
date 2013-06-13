$NetBSD: patch-libxorp_trie.hh,v 1.2 2013/06/13 21:48:09 joerg Exp $

--- libxorp/trie.hh.orig	2009-01-05 18:30:58.000000000 +0000
+++ libxorp/trie.hh
@@ -277,6 +277,7 @@ private:
 
     void dump(const char *msg) const
     {
+	(void)msg;
 	trie_debug_msg(" %s %s %s\n",
 		       msg,
 		       _k.str().c_str(), _p ? "PL" : "[]");
@@ -372,6 +373,9 @@ public:
     bool operator==(const TriePostOrderIterator & x) const {
 	return (_cur == x._cur); 
     }
+    bool operator!=(const TriePostOrderIterator & x) const {
+	return (_cur != x._cur);
+    }
 
     bool has_payload() const		{ return _cur->has_payload(); }
     Payload & payload()			{ return _cur->p(); };
