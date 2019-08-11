$NetBSD: patch-Makefile.SH,v 1.9 2019/08/11 10:14:18 adam Exp $

Use correct -install_name on Darwin.
Fix DTrace object generation.

--- Makefile.SH.orig	2019-05-11 23:02:19.000000000 +0000
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
@@ -278,6 +278,7 @@ LNS = $lns
 # NOTE: some systems don't grok "cp -f". XXX Configure test needed?
 CPS = $cp
 RMS = rm -f
+ECHO = $echo
 ranlib = $ranlib
 
 # The following are mentioned only to make metaconfig include the
