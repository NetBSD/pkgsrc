$NetBSD: patch-config-scripts_cups-manpages.m4,v 1.4 2017/01/21 11:57:10 leot Exp $

Add '--with-manext' configure option.

--- config-scripts/cups-manpages.m4.orig	2017-01-17 19:27:22.000000000 +0000
+++ config-scripts/cups-manpages.m4
@@ -11,6 +11,8 @@ dnl which should have been included with
 dnl missing or damaged, see the license at "http://www.cups.org/".
 dnl
 
+AC_ARG_WITH(manext, [  --with-manext           set man page extension style (bsd,irix,sysv,none)],manext="$withval",manext="")
+
 dnl Fix "mandir" variable...
 if test "$mandir" = "\${datarootdir}/man" -a "$prefix" = "/"; then
 	# New GNU "standards" break previous ones, so make sure we use
@@ -42,7 +44,27 @@ AC_SUBST(AMANDIR)
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
@@ -51,7 +73,7 @@ case "$uname" in
 		MAN8EXT=1m
 		MAN8DIR=1m
 		;;
-	Linux* | GNU* | Darwin*)
+	linux)
 		# Linux, GNU Hurd, and macOS
 		MAN1EXT=1.gz
 		MAN5EXT=5.gz
@@ -59,7 +81,7 @@ case "$uname" in
 		MAN8EXT=8.gz
 		MAN8DIR=8
 		;;
-	*)
+	none|*)
 		# All others
 		MAN1EXT=1
 		MAN5EXT=5
