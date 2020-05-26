$NetBSD: patch-config-scripts_cups-libtool.m4,v 1.2 2020/05/26 08:36:56 triaxx Exp $

Fix non-portable `==' test(1) operator.

--- config-scripts/cups-libtool.m4.orig	2017-10-13 18:22:26.000000000 +0000
+++ config-scripts/cups-libtool.m4
@@ -10,7 +10,7 @@ dnl
 AC_ARG_ENABLE(libtool_unsupported, [  --enable-libtool-unsupported=/path/to/libtool
                           build with libtool (UNSUPPORTED!)],
 	[if test x$enable_libtool_unsupported != xno; then
-		if test x$enable_libtool_unsupported == xyes; then
+		if test x$enable_libtool_unsupported = xyes; then
 			AC_MSG_ERROR([Use --enable-libtool-unsupported=/path/to/libtool.])
 		fi
 		LIBTOOL="$enable_libtool_unsupported"
