$NetBSD: patch-lib_File_BaseDir.pm,v 1.2 2023/05/20 07:18:56 wiz Exp $

Look in pkgsrc's sharedir, too.

--- lib/File/BaseDir.pm.orig	2021-07-08 20:04:16.000000000 +0000
+++ lib/File/BaseDir.pm
@@ -46,7 +46,7 @@ sub xdg_data_home { $ENV{XDG_DATA_HOME} 
 sub xdg_data_dirs {
   ( $ENV{XDG_DATA_DIRS}
     ? _adapt($ENV{XDG_DATA_DIRS})
-    : (File::Spec->catdir(_rootdir(), qw/usr local share/), File::Spec->catdir(_rootdir(), qw/usr share/))
+    : (File::Spec->catdir(_rootdir(), qw/@SHAREDIR_SPLIT@/), File::Spec->catdir(_rootdir(), qw/usr local share/), File::Spec->catdir(_rootdir(), qw/usr share/))
   )
 }
 
