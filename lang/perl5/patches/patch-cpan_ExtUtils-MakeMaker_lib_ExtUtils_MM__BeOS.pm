$NetBSD: patch-cpan_ExtUtils-MakeMaker_lib_ExtUtils_MM__BeOS.pm,v 1.1 2021/03/15 14:23:12 ryoon Exp $

* Fix libperl.so reference.

--- cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_BeOS.pm.orig	2020-12-18 10:04:35.000000000 +0000
+++ cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_BeOS.pm
@@ -49,8 +49,7 @@ libperl.a equivalent to be linked to dyn
 sub init_linker {
     my($self) = shift;
 
-    $self->{PERL_ARCHIVE} ||=
-      File::Spec->catdir('$(PERL_INC)',$Config{libperl});
+    $self->{PERL_ARCHIVE} ||= '';
     $self->{PERL_ARCHIVEDEP} ||= '';
     $self->{PERL_ARCHIVE_AFTER} ||= '';
     $self->{EXPORT_LIST}  ||= '';
