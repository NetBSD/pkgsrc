$NetBSD: patch-config-scripts_cups-opsys.m4,v 1.2 2018/04/05 16:31:45 leot Exp $

Fix building on newer macOS.

--- config-scripts/cups-opsys.m4.orig	2018-03-23 03:48:36.000000000 +0000
+++ config-scripts/cups-opsys.m4
@@ -22,9 +22,6 @@ if test "x$host_os_version" = x; then
         host_os_version="0"
 fi
 
-if test "$host_os_name" = darwin -a $host_os_version -lt 120; then
-        AC_MSG_ERROR([Sorry, this version of CUPS requires macOS 10.8 or higher.])
-fi
 
 dnl Determine whether we are cross-compiling...
 if test "$build" = "$host"; then
