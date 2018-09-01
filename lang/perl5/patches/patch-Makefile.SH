$NetBSD: patch-Makefile.SH,v 1.7 2018/09/01 08:03:02 schmonz Exp $

Fix DTrace object generation.
Fix Storable build on OS X where DYLD_LIBRARY_PATH is no longer
inherited by child processes.

--- Makefile.SH.orig	2018-05-21 13:22:09.000000000 +0000
+++ Makefile.SH
@@ -275,6 +275,7 @@ LNS = $lns
 # NOTE: some systems don't grok "cp -f". XXX Configure test needed?
 CPS = $cp
 RMS = rm -f
+ECHO = $echo
 ranlib = $ranlib
 
 # The following are mentioned only to make metaconfig include the
@@ -1167,7 +1168,7 @@ esac
 $spitshell >>$Makefile <<EOT
 
 dist/Storable/lib/Storable/Limit.pm : \$(PERL_EXE) dist/Storable/stacksize $storable_limit_dep
-	cd dist/Storable ; \$(LDLIBPTH) \$(MAKE) lib/Storable/Limit.pm
+	cd dist/Storable ; LDLIBPTH=\$(LDLIBPTH) \$(MAKE) lib/Storable/Limit.pm
 
 lib/Storable/Limit.pm : dist/Storable/lib/Storable/Limit.pm
 	test -d lib/Storable || mkdir lib/Storable
