$NetBSD: patch-inc_MyBuilder.pm,v 1.1 2012/05/23 20:57:29 markd Exp $

Fix linking of btparse library into xscode object

--- inc/MyBuilder.pm.orig	2012-01-11 15:01:26.000000000 +0000
+++ inc/MyBuilder.pm
@@ -120,7 +120,7 @@ sub ACTION_compile_xscode {
         my $btparselibdir = $self->install_path('usrlib');
         $cbuilder->link(
                         module_name => 'Text::BibTeX',
-                        extra_linker_flags => "-Lbtparse/src -lbtparse ",
+                        extra_linker_flags => "-Lbtparse/src -Wl,-R${btparselibdir} -lbtparse ",
                         objects     => $objects,
                         lib_file    => $lib_file,
                        );
