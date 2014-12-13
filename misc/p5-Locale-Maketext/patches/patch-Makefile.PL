$NetBSD: patch-Makefile.PL,v 1.1 2014/12/13 04:11:18 mef Exp $

WARN: Makefile:13: Unusual value for PERL5_PACKLIST -- "auto/Locale/Maketext/.packlist" expected.

--- Makefile.PL~	2014-12-05 05:40:54.000000000 +0900
+++ Makefile.PL	2014-12-13 13:04:08.000000000 +0900
@@ -3,7 +3,7 @@ use strict;
 use ExtUtils::MakeMaker;
 
 WriteMakefile(
-    NAME            => 'Locale-Maketext',
+    NAME            => 'Locale/Maketext',
     VERSION_FROM    => 'lib/Locale/Maketext.pm',
     ABSTRACT_FROM   => 'lib/Locale/Maketext.pod',
     PREREQ_PM       => {
