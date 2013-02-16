$NetBSD: patch-t_01__vars.t,v 1.1 2013/02/16 22:14:41 schmonz Exp $

Look in pkgsrc's sharedir, too.

--- t/01_vars.t.orig	2007-10-24 19:57:22.000000000 +0000
+++ t/01_vars.t
@@ -29,7 +29,8 @@ ok( xdg_data_home() eq 'test123', 'xdg_d
 
 $ENV{XDG_DATA_DIRS} = '';
 is_deeply( [xdg_data_dirs()],
-           [ File::Spec->catdir($rootdir, qw/usr local share/),
+           [ File::Spec->catdir($rootdir, qw/@SHAREDIR_SPLIT@/),
+             File::Spec->catdir($rootdir, qw/usr local share/),
              File::Spec->catdir($rootdir, qw/usr share/)         ],
 	   'xdg_data_dirs default');
 $ENV{XDG_DATA_DIRS} = './t:foo:bar';
