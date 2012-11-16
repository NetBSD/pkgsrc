$NetBSD: patch-build_autoconf_moznbytetype.m4,v 1.1 2012/11/16 00:48:21 joerg Exp $

--- build/autoconf/moznbytetype.m4.orig	2012-11-08 15:20:19.000000000 +0000
+++ build/autoconf/moznbytetype.m4
@@ -60,7 +60,7 @@ AC_CACHE_CHECK([for a $2-byte type], moz
     AC_TRY_COMPILE([],
                    [
                      int a[sizeof ($type) == $2 ? 1 : -1];
-                     return;
+                     return 0;
                    ],
                    [moz_cv_n_byte_type_$1=$type; break], [])
   done
@@ -91,7 +91,7 @@ AC_CACHE_CHECK([for the size of $2], moz
     AC_TRY_COMPILE([],
                    [
                      int a[sizeof ($2) == $size ? 1 : -1];
-                     return;
+                     return 0;
                    ],
                    [moz_cv_size_of_$1=$size; break], [])
   done
@@ -124,7 +124,7 @@ AC_CACHE_CHECK([for the alignment of $2]
                    ],
                    [
                      int a[offsetof(struct aligner, a) == $align ? 1 : -1];
-                     return;
+                     return 0;
                    ],
                    [moz_cv_align_of_$1=$align; break], [])
   done
