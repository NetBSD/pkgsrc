$NetBSD: patch-plugin-configure.m4,v 1.4 2019/11/26 16:54:13 nia Exp $

* adapt wordperfect plugins to dependecies available in pkgsrc 
  from abiword svn date 2014-12-27

--- plugin-configure.m4.orig	2019-11-24 22:57:35.000000000 +0000
+++ plugin-configure.m4
@@ -691,7 +691,7 @@ AC_SUBST([RSVG_CFLAGS])
 AC_SUBST([RSVG_LIBS])
 
 
-wpg_pkgs="$gsf_req libwpg-0.2 >= 0.2.0 libwpd-0.9 >= 0.9.0 libwpd-stream-0.9 >= 0.9.0"
+wpg_pkgs="libwpg-0.3 $gsf_req"
 wpg_deps="no"
 
 if test "$enable_wpg" != ""; then
@@ -1797,8 +1797,8 @@ AC_SUBST([FREETRANSLATION_CFLAGS])
 AC_SUBST([FREETRANSLATION_LIBS])
 
 
-wordperfect_pkgs="libwpg-0.2 >= 0.2.0 libwpd-0.9 >= 0.9.0 libwpd-stream-0.9 >= 0.9.0 $gsf_req"
-wordperfect_wps_pkgs='libwps-0.2 >= 0.1.0'
+wordperfect_pkgs="libwpd-0.10 $gsf_req"
+wordperfect_wps_pkgs='libwps-0.3'
 wordperfect_deps="no"
 
 WORDPERFECT_CFLAGS=
