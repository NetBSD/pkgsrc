$NetBSD: patch-src_hunspell_phonet.cxx,v 1.1 2026/09/30 09:10:08 adam Exp $

--- src/hunspell/phonet.cxx.orig	2022-12-29 20:10:49.000000000 +0000
+++ src/hunspell/phonet.cxx
@@ -35,6 +35,15 @@
 #include "csutil.hxx"
 #include "phonet.hxx"
 
+#ifdef __SUNPRO_CC
+using std::isalpha;
+using std::isdigit;
+using std::strchr;
+using std::strcpy;
+using std::strlen;
+using std::strstr;
+#endif
+
 void init_phonet_hash(phonetable& parms) {
   memset(parms.hash, 0xff, HASHSIZE * sizeof(int));
 
