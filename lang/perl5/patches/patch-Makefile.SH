$NetBSD: patch-Makefile.SH,v 1.8 2019/04/23 09:27:46 adam Exp $

Use correct -install_name on Darwin.
Fix DTrace object generation.
Fix Storable build on OS X where DYLD_LIBRARY_PATH is no longer
inherited by child processes.

--- Makefile.SH.orig	2019-04-02 22:36:35.000000000 +0200
+++ Makefile.SH	2019-04-23 10:07:15.000000000 +0200
@@ -70,7 +70,7 @@
 				${revision}.${patchlevel}.${subversion}"
 		case "$osvers" in
 	        1[5-9]*|[2-9]*)
-			shrpldflags="$shrpldflags -install_name `pwd`/\$@ -Xlinker -headerpad_max_install_names"
+			shrpldflags="$shrpldflags -install_name \$(shrpdir)/\$@ -Xlinker -headerpad_max_install_names"
 			exeldflags="-Xlinker -headerpad_max_install_names"
 			;;
 		*)
@@ -283,6 +283,7 @@
 # NOTE: some systems don't grok "cp -f". XXX Configure test needed?
 CPS = $cp
 RMS = rm -f
+ECHO = $echo
 ranlib = $ranlib
 
 # The following are mentioned only to make metaconfig include the
@@ -1197,7 +1198,7 @@
 $spitshell >>$Makefile <<EOT
 
 dist/Storable/lib/Storable/Limit.pm : \$(PERL_EXE) dist/Storable/stacksize $storable_limit_dep
-	cd dist/Storable ; \$(LDLIBPTH) \$(MAKE) lib/Storable/Limit.pm
+	cd dist/Storable ; LDLIBPTH=\$(LDLIBPTH) \$(MAKE) lib/Storable/Limit.pm
 
 lib/Storable/Limit.pm : dist/Storable/lib/Storable/Limit.pm
 	test -d lib/Storable || mkdir lib/Storable
