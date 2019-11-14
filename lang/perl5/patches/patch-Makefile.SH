$NetBSD: patch-Makefile.SH,v 1.10 2019/11/14 09:56:56 adam Exp $

Use correct -install_name on Darwin.

--- Makefile.SH.orig	2019-10-24 21:27:53.000000000 +0000
+++ Makefile.SH
@@ -70,7 +70,7 @@ true)
 				${revision}.${patchlevel}.${subversion}"
 		case "$osvers" in
 	        1[5-9]*|[2-9]*)
-			shrpldflags="$shrpldflags -install_name `pwd`/\$@ -Xlinker -headerpad_max_install_names"
+			shrpldflags="$shrpldflags -install_name \$(shrpdir)/\$@ -Xlinker -headerpad_max_install_names"
 			exeldflags="-Xlinker -headerpad_max_install_names"
 			;;
 		*)
