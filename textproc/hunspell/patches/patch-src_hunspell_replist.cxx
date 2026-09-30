$NetBSD: patch-src_hunspell_replist.cxx,v 1.1 2026/09/30 09:10:08 adam Exp $

--- src/hunspell/replist.cxx.orig	2026-09-27 15:18:58.000000000 +0000
+++ src/hunspell/replist.cxx
@@ -76,6 +76,15 @@
 #include "replist.hxx"
 #include "csutil.hxx"
 
+#ifdef __SUNPRO_CC
+using std::free;
+using std::malloc;
+using std::strcmp;
+using std::strcpy;
+using std::strlen;
+using std::strncmp;
+#endif
+
 RepList::RepList(int n) {
   dat.reserve(std::min(n, 16384));
   can_use_trie = true;
