$NetBSD: patch-aclocal.m4,v 1.1 2011/06/26 12:46:06 obache Exp $

* from patch-ab

--- aclocal.m4.orig	2010-09-28 14:13:32.000000000 +0000
+++ aclocal.m4
@@ -672,11 +672,7 @@ glib_save_datarootdir="$datarootdir"
 test "x$prefix" = xNONE && prefix=$ac_default_prefix
 test "x$exec_prefix" = xNONE && exec_prefix=$prefix
 datarootdir=`eval echo "${datarootdir}"`
-if test "x$CATOBJEXT" = "x.mo" ; then
-  localedir=`eval echo "${libdir}/locale"`
-else
-  localedir=`eval echo "${datadir}/locale"`
-fi
+localedir="$prefix/$PKGLOCALEDIR/locale"
 prefix="$glib_save_prefix"
 exec_prefix="$glib_save_exec_prefix"
 datarootdir="$glib_save_datarootdir"
