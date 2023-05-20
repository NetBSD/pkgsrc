$NetBSD: patch-t_01__vars.t,v 1.2 2023/05/20 07:18:56 wiz Exp $

Look in pkgsrc's sharedir, too.

--- t/01_vars.t.orig	2021-07-08 20:04:16.000000000 +0000
+++ t/01_vars.t
@@ -33,7 +33,8 @@ ok( xdg_data_home() eq 'test123', 'xdg_d
 
 $ENV{XDG_DATA_DIRS} = '';
 is_deeply( [xdg_data_dirs()],
-           [ File::Spec->catdir(File::BaseDir->_rootdir, qw/usr local share/),
+           [ File::Spec->catdir(File::BaseDir->_rootdir, qw/@SHAREDIR_SPLIT@/),
+             File::Spec->catdir(File::BaseDir->_rootdir, qw/usr local share/),
              File::Spec->catdir(File::BaseDir->_rootdir, qw/usr share/)         ],
      'xdg_data_dirs default');
 $ENV{XDG_DATA_DIRS} = join $Config{path_sep}, qw/ t foo bar /;
