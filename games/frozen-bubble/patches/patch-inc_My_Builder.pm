$NetBSD: patch-inc_My_Builder.pm,v 1.1 2024/11/25 16:05:03 leot Exp $

Use numeric version.

Makes it compatible with Perl 5.40.

--- inc/My/Builder.pm.orig	2010-08-07 13:36:27.000000000 +0000
+++ inc/My/Builder.pm
@@ -8,7 +8,7 @@ use File::Copy qw(move);
 use File::Slurp qw(read_file write_file);
 use File::Spec::Functions qw(catdir catfile rootdir);
 use IO::File qw();
-use Module::Build '0.36' => qw();
+use Module::Build 0.36 qw();
 use autodie qw(:all move read_file write_file);
 use parent 'Module::Build';
 use Locale::Maketext::Extract;
