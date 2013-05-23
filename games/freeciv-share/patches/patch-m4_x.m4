$NetBSD: patch-m4_x.m4,v 1.1 2013/05/23 15:02:53 joerg Exp $

--- m4/x.m4.orig	2013-05-22 20:15:33.000000000 +0000
+++ m4/x.m4
@@ -64,13 +64,13 @@ AC_DEFUN([FC_CHECK_X_LIB], [
     AH_TEMPLATE([HAVE_LIBXPM], [Define if the Xpm lib is available])
     AH_TEMPLATE([HAVE_LIBXAW], [Define if the Xaw lib is to be used])
     AH_TEMPLATE([HAVE_LIBXAW3D], [Define if the Xaw3d lib is to be used])
-    if (test $ac_tr_lib == HAVE_LIBX11     \
-        || test $ac_tr_lib == HAVE_LIBXEXT \
-        || test $ac_tr_lib == HAVE_LIBXT   \
-        || test $ac_tr_lib == HAVE_LIBXMU  \
-        || test $ac_tr_lib == HAVE_LIBXPM  \
-        || test $ac_tr_lib == HAVE_LIBXAW  \
-        || test $ac_tr_lib == HAVE_LIBXAW3D); then
+    if (test $ac_tr_lib = HAVE_LIBX11     \
+        || test $ac_tr_lib = HAVE_LIBXEXT \
+        || test $ac_tr_lib = HAVE_LIBXT   \
+        || test $ac_tr_lib = HAVE_LIBXMU  \
+        || test $ac_tr_lib = HAVE_LIBXPM  \
+        || test $ac_tr_lib = HAVE_LIBXAW  \
+        || test $ac_tr_lib = HAVE_LIBXAW3D); then
       AC_DEFINE_UNQUOTED($ac_tr_lib)
       X_EXTRA_LIBS="-l$1 $X_EXTRA_LIBS"
     else
