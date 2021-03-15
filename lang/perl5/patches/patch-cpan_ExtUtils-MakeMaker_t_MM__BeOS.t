$NetBSD: patch-cpan_ExtUtils-MakeMaker_t_MM__BeOS.t,v 1.1 2021/03/15 14:23:12 ryoon Exp $

* Fix libperl.so reference.

--- cpan/ExtUtils-MakeMaker/t/MM_BeOS.t.orig	2020-12-18 10:04:35.000000000 +0000
+++ cpan/ExtUtils-MakeMaker/t/MM_BeOS.t
@@ -38,8 +38,7 @@ my $MM = bless { NAME => "Foo" }, 'MM';
 
 # init_linker
 {
-    my $libperl = File::Spec->catfile('$(PERL_INC)',
-                                      $Config{libperl} || 'libperl.a' );
+    my $libperl = '';
     my $export  = '';
     my $after   = '';
     $MM->init_linker;
