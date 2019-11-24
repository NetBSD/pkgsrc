$NetBSD: patch-lib_tree.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8084/
Add guards around GCC diagnostics pragma to allow for building on older vers

--- lib/tree.c.orig	2019-07-23 14:46:51.000000000 +0000
+++ lib/tree.c
@@ -472,8 +472,10 @@ void *xtreeDelete(void *treehandle, char
 
 
 #ifdef STANDALONE
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wunused-result"
+#endif  // __GNUC__
 
 int main(int argc, char **argv)
 {
@@ -542,6 +544,8 @@ int main(int argc, char **argv)
 
 	return 0;
 }
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 #pragma GCC diagnostic pop
+#endif  // __GNUC__
 #endif
 
