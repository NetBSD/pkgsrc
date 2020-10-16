$NetBSD: patch-config-scripts_cups-dnssd.m4,v 1.1 2020/10/16 15:11:13 prlw1 Exp $

Build ippfind if dnssd is found (not just avahi).
This seems to be the intention of cups commit 766a822, but a comma got in the way.

--- config-scripts/cups-dnssd.m4.orig	2020-04-27 18:04:29.000000000 +0000
+++ config-scripts/cups-dnssd.m4
@@ -60,9 +60,9 @@ if test "x$DNSSD_BACKEND" = x -a x$enabl
 					AC_MSG_RESULT(yes)
 					AC_DEFINE(HAVE_DNSSD)
 					DNSSDLIBS="-ldns_sd"
-					DNSSD_BACKEND="dnssd",
+					DNSSD_BACKEND="dnssd"
 					IPPFIND_BIN="ippfind"
-					IPPFIND_MAN="ippfind.1"
+					IPPFIND_MAN="ippfind.1",
 					AC_MSG_RESULT(no))
 				LIBS="$SAVELIBS"
 				;;
