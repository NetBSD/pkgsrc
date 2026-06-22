$NetBSD: patch-lib_autoconf_fortran.m4,v 1.2 2026/06/22 17:53:58 wiz Exp $

Rpath is a linker option, so prefix it with -Wl.

--- lib/autoconf/fortran.m4.orig	2014-02-24 14:06:39.000000000 +0000
+++ lib/autoconf/fortran.m4
@@ -692,6 +692,11 @@ while test $[@%:@] != 1; do
 	  done
 	  ;;
 	-[[lLR]]*)
+	    case $ac_arg in
+	    -R*)
+	        ac_arg="-Wl,$ac_arg"
+	        ;;
+	    esac
 	  _AC_LIST_MEMBER_IF($ac_arg, $ac_cv_[]_AC_LANG_ABBREV[]_libs, ,
 			     ac_cv_[]_AC_LANG_ABBREV[]_libs="$ac_cv_[]_AC_LANG_ABBREV[]_libs $ac_arg")
 	  ;;
