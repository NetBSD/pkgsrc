$NetBSD: patch-lib_autoconf_fortran.m4,v 1.1 2014/03/06 15:41:50 joerg Exp $

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
