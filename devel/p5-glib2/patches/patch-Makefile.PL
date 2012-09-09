$NetBSD: patch-Makefile.PL,v 1.1 2012/09/09 12:50:05 abs Exp $

Revert "configure_requires =>" to "prereqs => configure => requires =>" change
introduced in Glib-1.262 to avoid following build error:

ExtUtils::MakeMaker::YAML does not support circular references at
  /usr/pkg/lib/perl5/5.14.0/ExtUtils/MakeMaker/YAML.pm line 499.

--- Makefile.PL.orig	2012-09-09 12:43:32.000000000 +0000
+++ Makefile.PL
@@ -118,11 +118,7 @@ my %meta_merge = (
                     web     => 'http://git.gnome.org/browse/perl-Glib',
             },
         },
-        prereqs => {
-            configure => {
-                requires => \%PREREQ_PM,
-            },
-        },
+        configure_requires => \%PREREQ_PM,
         no_index => {
             file => [@xs_files, qw/Makefile.PL xsapi.pod.head xsapi.pod.foot/],
             package => 'MY',
