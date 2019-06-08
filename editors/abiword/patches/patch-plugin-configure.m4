$NetBSD: patch-plugin-configure.m4,v 1.3 2019/06/08 10:40:53 rillig Exp $

* adapt wordperfect plugins to dependecies available in pkgsrc 
  from abiword svn date 2014-12-27

--- plugin-configure.m4.orig	2016-10-21 00:42:58.000000000 +0000
+++ plugin-configure.m4
@@ -72,7 +72,7 @@ AC_SUBST([GRAMMAR_CFLAGS])
 AC_SUBST([GRAMMAR_LIBS])
 
 
-wpg_pkgs="$gsf_req libwpg-0.2 >= 0.2.0 libwpd-0.9 >= 0.9.0 libwpd-stream-0.9 >= 0.9.0"
+wpg_pkgs="libwpg-0.3 $gsf_req"
 wpg_deps="no"
 
 if test "$enable_wpg" != ""; then
@@ -962,8 +962,8 @@ AC_SUBST([XSLFO_CFLAGS])
 AC_SUBST([XSLFO_LIBS])
 
 
-wordperfect_pkgs="libwpg-0.2 >= 0.2.0 libwpd-0.9 >= 0.9.0 libwpd-stream-0.9 >= 0.9.0 $gsf_req"
-wordperfect_wps_pkgs='libwps-0.2 >= 0.1.0'
+wordperfect_pkgs="libwpd-0.10 $gsf_req"
+wordperfect_wps_pkgs='libwps-0.3'
 wordperfect_deps="no"
 
 WORDPERFECT_CFLAGS=
