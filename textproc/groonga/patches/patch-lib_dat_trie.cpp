$NetBSD: patch-lib_dat_trie.cpp,v 1.1 2011/07/11 08:32:38 obache Exp $

* *BSD have MAP_ANONY not MAP_ANONYMOUS.
  https://github.com/groonga/groonga/commit/6a6362a00df314c734dfdd40d59671b1b64e53df

--- lib/dat/trie.cpp.orig	2011-06-28 12:51:56.000000000 +0000
+++ lib/dat/trie.cpp
@@ -9,6 +9,10 @@
 #include <algorithm>
 #include <cstring>
 
+#if defined(MAP_ANON) && !defined(MAP_ANONYMOUS)
+#define MAP_ANONYMOUS MAP_ANON
+#endif
+
 namespace grn {
 namespace dat {
 
