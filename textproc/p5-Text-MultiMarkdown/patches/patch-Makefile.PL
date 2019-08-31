$NetBSD: patch-Makefile.PL,v 1.1 2019/08/31 19:55:58 schmonz Exp $

Find the bundled Module::Install.

--- Makefile.PL.orig	2014-07-19 16:58:56.000000000 +0000
+++ Makefile.PL
@@ -1,4 +1,5 @@
 # Load the Module::Install bundled in ./inc/
+use lib '.';
 use inc::Module::Install;
 
 # Define metadata
