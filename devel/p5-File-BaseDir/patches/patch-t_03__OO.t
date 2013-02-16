$NetBSD: patch-t_03__OO.t,v 1.1 2013/02/16 22:14:42 schmonz Exp $

Look in pkgsrc's sharedir, too.

--- t/03_OO.t.orig	2007-10-24 19:57:22.000000000 +0000
+++ t/03_OO.t
@@ -10,7 +10,8 @@ is(ref($conf), 'File::BaseDir', 'OO cons
 
 $ENV{XDG_DATA_DIRS} = '';
 is_deeply( [$conf->xdg_data_dirs()],
-           [ File::Spec->catdir($rootdir, qw/usr local share/),
+           [ File::Spec->catdir($rootdir, qw/@SHAREDIR_SPLIT@/),
+             File::Spec->catdir($rootdir, qw/usr local share/),
              File::Spec->catdir($rootdir, qw/usr share/)         ],
 	   'xdg_data_dirs default - OO');
 
