$NetBSD: patch-src_hb-open-type-private.hh,v 1.3 2014/06/05 16:36:19 wiz Exp $

Fix build with gcc 4.2.1 of FreeBSD 9.1.

Patch is taken from
https://build.opensuse.org/package/view_file?file=mozilla-gcc43.patch&package=MozillaFirefox&project=home%3AWernerFink%3Abranches%3Amozilla

--- src/hb-open-type-private.hh.orig	2014-05-14 01:47:24.000000000 +0000
+++ src/hb-open-type-private.hh
@@ -958,6 +958,11 @@ struct HeadlessArrayOf
   DEFINE_SIZE_ARRAY (sizeof (USHORT), array);
 };
 
+#if __GNUC__ && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 4))
+// work around GCC 4.3 bug where the search() function gets improperly
+// optimized away from some instantiations of this template
+#pragma GCC visibility push(default)
+#endif
 
 /* An array with sorted elements.  Supports binary searching. */
 template <typename LenType, typename Type>
@@ -990,5 +995,8 @@ struct SortedArrayOf : GenericSortedArra
 
 } /* namespace OT */
 
+#if __GNUC__ && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 4))
+#pragma GCC visibility pop
+#endif
 
 #endif /* HB_OPEN_TYPE_PRIVATE_HH */
