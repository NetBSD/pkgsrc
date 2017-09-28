$NetBSD: patch-Makefile.PL,v 1.1 2017/09/28 04:45:11 wiz Exp $

Fix build on NetBSD.
https://github.com/jonathanstowe/Sys-Utmp/issues/1

--- Makefile.PL.orig	2013-10-27 08:58:56.000000000 +0000
+++ Makefile.PL
@@ -8,7 +8,7 @@ my (
 # This may require some refinement
 if ( $^O =~ /netbsd/i )
 {
-    $defined = "";
+   $define = '-DNOUTFUNCS';
 }
 elsif ( $^O =~ /bsd/i )
 {
