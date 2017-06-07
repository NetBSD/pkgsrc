$NetBSD: patch-File-NFSLock.spec.PL,v 1.1 2017/06/07 23:49:25 ryoon Exp $

* Fix build with Perl 5.26.0

--- File-NFSLock.spec.PL.orig	2014-05-29 19:45:42.000000000 +0000
+++ File-NFSLock.spec.PL
@@ -18,7 +18,7 @@ sub WriteMakefile {
   } elsif (my $version_from = $props{VERSION_FROM}) {
     $@ = "";
     $version = eval qq{
-      do "$version_from";
+      do "./$version_from";
       \$$name\::VERSION || die "$version_from: Missing VERSION";
     };
     die $@ if $@;
@@ -29,7 +29,7 @@ sub WriteMakefile {
     die "Makefile.PL: Could not determine version!";
   }
 }
-do "Makefile.PL";
+do "./Makefile.PL";
 if ($name) {
   $name =~ s/::/-/g;
 } else {
