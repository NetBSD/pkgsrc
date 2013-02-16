$NetBSD: patch-lib_File_BaseDir.pm,v 1.1 2013/02/16 22:14:41 schmonz Exp $

Look in pkgsrc's sharedir, too.

--- lib/File/BaseDir.pm.orig	2007-10-24 19:57:22.000000000 +0000
+++ lib/File/BaseDir.pm
@@ -41,6 +41,7 @@ unless ($home) {
 # Set defaults
 our $xdg_data_home = File::Spec->catdir($home, qw/.local share/);
 our @xdg_data_dirs = (
+	File::Spec->catdir($rootdir, qw/@SHAREDIR_SPLIT@/),
 	File::Spec->catdir($rootdir, qw/usr local share/),
 	File::Spec->catdir($rootdir, qw/usr share/),
 );
