$NetBSD: patch-src_hb-open-type-private.hh,v 1.2 2013/07/07 10:23:14 wiz Exp $

Fix build with gcc 4.2.1 of FreeBSD 9.1.

Patch is taken from
https://build.opensuse.org/package/view_file?file=mozilla-gcc43.patch&package=MozillaFirefox&project=home%3AWernerFink%3Abranches%3Amozilla

--- src/hb-open-type-private.hh.orig	2013-01-08 22:13:42.000000000 +0000
+++ src/hb-open-type-private.hh
@@ -941,6 +941,11 @@ struct HeadlessArrayOf
   DEFINE_SIZE_ARRAY (sizeof (USHORT), array);
 };
 
+#if __GNUC__ && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 4))
+// work around GCC 4.3 bug where the search() function gets improperly
+// optimized away from some instantiations of this template
+#pragma GCC visibility push(default)
+#endif
 
 /* An array with sorted elements.  Supports binary searching. */
 template <typename Type>
@@ -968,5 +973,8 @@ struct SortedArrayOf : ArrayOf<Type> {
 
 } /* namespace OT */
 
+#if __GNUC__ && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 4))
+#pragma GCC visibility pop
+#endif
 
 #endif /* HB_OPEN_TYPE_PRIVATE_HH */
