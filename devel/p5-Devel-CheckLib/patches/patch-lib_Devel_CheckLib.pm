$NetBSD: patch-lib_Devel_CheckLib.pm,v 1.4 2024/04/25 17:56:30 schmonz Exp $

Fix regression reported in https://github.com/mattn/p5-Devel-CheckLib/issues/23.
Keeps p5-Crypt-DH-GMP building on at least NetBSD.
macOS doesn't use -rpath and older linkers don't recognize it.

--- lib/Devel/CheckLib.pm.orig	2022-05-04 14:31:10.000000000 +0000
+++ lib/Devel/CheckLib.pm
@@ -295,7 +295,6 @@ sub _compile_cmd {
 	    $cfile,
 	    (!defined $lib ? () : (
 	      (map "-L$_", @$libpaths),
-	      ($^O eq 'darwin' ? (map { "-Wl,-rpath,$_" } @$libpaths) : ()),
 	      "-l$lib",
 	    )),
 	    @$ld,
@@ -454,7 +453,7 @@ sub _findcc {
         push @Config_ldflags, $config_val if ( $config_val =~ /\S/ );
     }
     my @ccflags = grep { length } _parsewords($Config_ccflags||'', $user_ccflags||'');
-    my @ldflags = grep { length && $_ !~ m/^-Wl/ } _parsewords(@Config_ldflags, $user_ldflags||'');
+    my @ldflags = grep { length } _parsewords(@Config_ldflags, $user_ldflags||'');
     my @paths = split(/$Config{path_sep}/, $ENV{PATH});
     my @cc = _parsewords($Config{cc});
     if (check_compiler ($cc[0], $debug)) {
