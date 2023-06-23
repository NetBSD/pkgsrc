$NetBSD: patch-config-scripts_cups-common.m4,v 1.1 2023/06/23 06:46:48 wiz Exp $

Build libcupsimage with libcups, like in older versions of cups.

--- config-scripts/cups-common.m4.orig	2023-06-22 10:17:14.000000000 +0000
+++ config-scripts/cups-common.m4
@@ -474,7 +474,6 @@ AS_CASE(["$COMPONENTS"], [all], [
     LIBHEADERSPRIV="\$(COREHEADERSPRIV)"
 ], [libcups], [
     BUILDDIRS="locale"
-    cupsimagebase=""
 ], [libcupslite], [
     AC_DEFINE([CUPS_LITE], [1], [Building CUPS without driver support?])
     BUILDDIRS="locale"
