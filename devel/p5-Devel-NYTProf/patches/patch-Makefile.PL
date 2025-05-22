$NetBSD: patch-Makefile.PL,v 1.1 2025/05/22 19:11:52 schmonz Exp $

Find pkgsrc includes.

--- Makefile.PL.orig	2023-10-05 22:23:32.000000000 +0000
+++ Makefile.PL
@@ -71,7 +71,7 @@ my $h_files;
 my @h_dirs;
 push @h_dirs, split /:/, $ENV{INCLUDE} if $ENV{INCLUDE};
 push @h_dirs, split ' ', $Config{libsdirs};
-push @h_dirs, qw(/include /usr/include /usr/local/include /usr/include/mach);
+push @h_dirs, qw(@PREFIX@/include /usr/include);
 @h_dirs = grep { -d $_ } @h_dirs;
 
 $h_files = find_h_files(@h_dirs);
