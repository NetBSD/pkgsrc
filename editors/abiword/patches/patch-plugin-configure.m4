$NetBSD: patch-plugin-configure.m4,v 1.1 2015/09/13 21:32:13 nros Exp $
* adapt wordperfect plugins to dependecies available in pkgsrc 
  from abiword svn date 2014-12-27
--- plugin-configure.m4.orig	2014-12-23 05:13:14.000000000 +0000
+++ plugin-configure.m4
@@ -1355,7 +1355,7 @@ AC_SUBST([BMP_CFLAGS])
 AC_SUBST([BMP_LIBS])
 
 
-wpg_pkgs="$gsf_req libwpg-0.2 >= 0.2.0 libwpd-0.9 >= 0.9.0 libwpd-stream-0.9 >= 0.9.0"
+wpg_pkgs="libwpg-0.3 $gsf_req"
 wpg_deps="no"
 
 if test "$enable_wpg" != ""; then
@@ -1469,8 +1469,8 @@ AC_SUBST([AIKSAURUS_CFLAGS])
 AC_SUBST([AIKSAURUS_LIBS])
 
 
-wordperfect_pkgs="libwpg-0.2 >= 0.2.0 libwpd-0.9 >= 0.9.0 libwpd-stream-0.9 >= 0.9.0 $gsf_req"
-wordperfect_wps_pkgs='libwps-0.2 >= 0.1.0'
+wordperfect_pkgs="libwpd-0.10 $gsf_req"
+wordperfect_wps_pkgs='libwps-0.3'
 wordperfect_deps="no"
 
 WORDPERFECT_CFLAGS=
