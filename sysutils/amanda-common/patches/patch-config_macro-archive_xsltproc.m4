$NetBSD: patch-config_macro-archive_xsltproc.m4,v 1.1 2012/07/30 07:21:11 sbd Exp $

Fix shell portability problem.

--- config/macro-archive/xsltproc.m4.orig	2012-02-21 11:36:49.000000000 +0000
+++ config/macro-archive/xsltproc.m4
@@ -67,7 +67,7 @@ AS_HELP_STRING([--with-xsltproc[[[[[=PAT
 AC_ARG_WITH(xsltproc-flags,
 AS_HELP_STRING([  --with-xsltproc-flags=FLAGS],
                [Flags to pass to xsltproc (default $1)]),
-    [ if test "x$withval" == "xno"; then
+    [ if test "x$withval" = "xno"; then
 	XSLTPROC_FLAGS=''
     else
 	if test "x$withval" != "xyes"; then
