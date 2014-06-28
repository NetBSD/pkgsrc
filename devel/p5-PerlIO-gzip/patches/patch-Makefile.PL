$NetBSD: patch-Makefile.PL,v 1.1 2014/06/28 19:52:05 schmonz Exp $

Don't assume usesfio is core config (in Perl 5.20, it no longer is).

Patch from <https://rt.cpan.org/Public/Bug/Display.html?id=92412>.

--- Makefile.PL.orig	2006-10-01 21:28:25.000000000 +0000
+++ Makefile.PL
@@ -4,7 +4,8 @@ use 5.008; # Stop perl 5.005 or earler b
 use ExtUtils::MakeMaker;
 use Config;
 
-unless ($Config{useperlio} eq 'define' and $Config{usesfio} eq 'false') {
+unless ($Config{useperlio} eq 'define' and
+	(defined($Config{usesfio}) ? $Config{usesfio} : 'false') eq 'false') {
   die <<BARF;
 You need perl 5.8.0 or later, configured to use perlio (and not to use sfio)
 BARF
