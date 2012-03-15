$NetBSD: patch-build_autoconf_gcc-pr49911.m4,v 1.1.1.1 2012/03/15 08:58:27 ryoon Exp $

--- build/autoconf/gcc-pr49911.m4.orig	2012-03-09 22:20:09.000000000 +0000
+++ build/autoconf/gcc-pr49911.m4
@@ -56,7 +56,7 @@ CXXFLAGS="$_SAVE_CXXFLAGS"
 
 AC_LANG_RESTORE
 
-if test "$ac_have_gcc_pr49911" == "yes"; then
+if test "$ac_have_gcc_pr49911" = "yes"; then
    AC_MSG_RESULT(yes)
    CFLAGS="$CFLAGS -fno-tree-vrp"
    CXXFLAGS="$CXXFLAGS -fno-tree-vrp"
