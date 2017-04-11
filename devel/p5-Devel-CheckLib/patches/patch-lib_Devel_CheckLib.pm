$NetBSD: patch-lib_Devel_CheckLib.pm,v 1.1 2017/04/11 14:00:50 schmonz Exp $

Fix regression reported in https://github.com/mattn/p5-Devel-CheckLib/issues/23.

--- lib/Devel/CheckLib.pm.orig	2017-04-07 15:34:43.000000000 +0000
+++ lib/Devel/CheckLib.pm
@@ -473,7 +473,7 @@ sub _findcc {
         push @Config_ldflags, $config_val if ( $config_val =~ /\S/ );
     }
     my @ccflags = grep { length } quotewords('\s+', 1, $Config_ccflags||'', $user_ccflags||'');
-    my @ldflags = grep { length && $_ !~ m/^-Wl/ } quotewords('\s+', 1, @Config_ldflags, $user_ldflags||'');
+    my @ldflags = grep { length } quotewords('\s+', 1, @Config_ldflags, $user_ldflags||'');
     my @paths = split(/$Config{path_sep}/, $ENV{PATH});
     my @cc = split(/\s+/, $Config{cc});
     if (check_compiler ($cc[0], $debug)) {
