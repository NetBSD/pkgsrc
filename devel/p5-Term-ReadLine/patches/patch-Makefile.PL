$NetBSD: patch-Makefile.PL,v 1.1 2019/08/29 19:45:07 schmonz Exp $

Don't try to detect TERMCAP_LIB. Fixes at least Ubuntu builds.

--- Makefile.PL.orig	2017-11-25 13:50:24.000000000 +0000
+++ Makefile.PL
@@ -87,7 +87,7 @@ if ($Config{osname} eq 'os2') {
 	|| &search_lib('-lncurses')
 	|| &search_lib('-lcurses');
 
-    unless ($TERMCAP_LIB) {
+    unless (1 || $TERMCAP_LIB) {
 	warn "Could not find neither libtermcap, libtinfo, libncurses, or libcurses.\n";
 	exit $err;
     } 
