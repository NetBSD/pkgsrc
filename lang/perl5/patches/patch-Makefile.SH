$NetBSD: patch-Makefile.SH,v 1.11 2026/07/16 18:57:37 wiz Exp $

Use correct -install_name on Darwin.

--- Makefile.SH.orig	2026-06-23 00:51:45.000000000 +0000
+++ Makefile.SH
@@ -64,7 +64,7 @@ true)
 				${revision}.${patchlevel}.${subversion}"
 		case "$osvers" in
 	        1[5-9]*|[2-9]*)
-			shrpldflags="$shrpldflags -install_name `pwd -P`/\$@ -Xlinker -headerpad_max_install_names"
+			shrpldflags="$shrpldflags -install_name \$(shrpdir)/\$@ -Xlinker -headerpad_max_install_names"
 			exeldflags="-Xlinker -headerpad_max_install_names"
 			;;
 		*)
