$NetBSD: patch-config-scripts_cups-manpages.m4,v 1.1 2015/01/02 02:03:42 christos Exp $

Add '--with-manext' configure option.

--- config-scripts/cups-manpages.m4.orig	2013-10-18 16:36:01.000000000 -0400
+++ config-scripts/cups-manpages.m4	2014-12-24 14:30:03.000000000 -0500
@@ -13,6 +13,8 @@
 dnl file is missing or damaged, see the license at "http://www.cups.org/".
 dnl
 
+AC_ARG_WITH(manext, [  --with-manext           set man page extension style (bsd,irix,sysv,none)],manext="$withval",manext="")
+
 dnl Fix "mandir" variable...
 if test "$mandir" = "\${datarootdir}/man" -a "$prefix" = "/"; then
 	# New GNU "standards" break previous ones, so make sure we use
@@ -44,7 +46,27 @@
 AC_SUBST(PMANDIR)
 
 dnl Setup manpage extensions...
-case "$uname" in
+if test x$manext = x; then
+	case "$uname" in
+		*BSD* | DragonFly*)
+			# *BSD and Darwin (MacOS X)
+			manext=bsd
+			;;
+		SunOS* | HP-UX*)
+			# Solaris and HP-UX
+			manext=sysv
+			;;
+		Linux* | GNU* | Darwin*)
+			# Linux and GNU Hurd
+			manext=linux
+			;;
+		*)
+			# All others
+			;;
+	esac
+fi
+
+case "$manext" in
 	SunOS*)
 		# Solaris
 		MAN1EXT=1
@@ -53,7 +75,7 @@
 		MAN8EXT=1m
 		MAN8DIR=1m
 		;;
-	Linux* | GNU* | Darwin*)
+	linux)
 		# Linux, GNU Hurd, and OS X
 		MAN1EXT=1.gz
 		MAN5EXT=5.gz
@@ -61,7 +83,7 @@
 		MAN8EXT=8.gz
 		MAN8DIR=8
 		;;
-	*)
+	none|*)
 		# All others
 		MAN1EXT=1
 		MAN5EXT=5
