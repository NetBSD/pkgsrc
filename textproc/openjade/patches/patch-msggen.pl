$NetBSD: patch-msggen.pl,v 1.1 2012/10/04 20:59:24 tron Exp $

Fix build problem with Perl 5.16. Patch taken from Gentoo Linux:

https://bugs.gentoo.org/show_bug.cgi?id=420083

--- msggen.pl.orig	2002-10-20 22:47:23.000000000 +0100
+++ msggen.pl	2012-10-04 21:50:57.000000000 +0100
@@ -4,6 +4,7 @@
 # See the file COPYING for copying permission.
 
 use POSIX;
+use Getopt::Std;
 
 # Package and version.
 $package = 'openjade';
@@ -18,8 +19,7 @@
 undef $opt_l;
 undef $opt_p;
 undef $opt_t;
-do 'getopts.pl';
-&Getopts('l:p:t:');
+getopts('l:p:t:');
 $module = $opt_l;
 $pot_file = $opt_p;
 
@@ -72,7 +72,7 @@
     else {
 	$field[0] =~ /^[IWQXE][0-9]$/ || &error("invalid first field");;
 	$type[$num] = substr($field[0], 0, 1);
-	$argc = int(substr($field[0], 1, 1));
+	$argc = substr($field[0], 1, 1);
     }
     $nargs[$num] = $argc;
     $field[1] =~ /^[a-zA-Z_][a-zA-Z0-9_]+$/ || &error("invalid tag");
