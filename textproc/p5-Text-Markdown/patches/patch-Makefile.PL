$NetBSD: patch-Makefile.PL,v 1.1 2017/06/08 08:33:45 wiz Exp $

Fix build with perl-5.26.
https://github.com/ppisar/text-markdown/commit/0a122ccf1ef6e642cf5415b82ae9b51124151d63

--- Makefile.PL.orig	2010-03-20 23:05:43.000000000 +0000
+++ Makefile.PL
@@ -1,4 +1,5 @@
 # Load the Module::Install bundled in ./inc/
+BEGIN { push @INC, '.'; }
 use inc::Module::Install;
 
 # Define metadata
