$NetBSD: patch-config-scripts_cups-common.m4,v 1.1 2015/09/05 13:03:22 jperkin Exp $

Get rid of bogus OSX test.

--- config-scripts/cups-common.m4.orig	2012-07-25 20:43:57.000000000 +0000
+++ config-scripts/cups-common.m4
@@ -385,7 +385,7 @@ case $uname in
 		if test $uversion -ge 100; then
 			AC_CHECK_HEADER(sandbox.h,AC_DEFINE(HAVE_SANDBOX_H))
 		fi
-		if test $uversion -ge 110; then
+		if test $uversion -ge 999110; then
 			# Broken public headers in 10.7...
 			AC_MSG_CHECKING(for sandbox/private.h presence)
 			if test -f /usr/local/include/sandbox/private.h; then
