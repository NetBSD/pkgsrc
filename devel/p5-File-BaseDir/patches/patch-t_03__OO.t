$NetBSD: patch-t_03__OO.t,v 1.2 2023/05/20 07:18:56 wiz Exp $

Look in pkgsrc's sharedir, too.

--- t/03_OO.t.orig	2021-07-08 20:04:16.000000000 +0000
+++ t/03_OO.t
@@ -14,7 +14,8 @@ isa_ok $conf, 'File::BaseDir';
 
   $ENV{XDG_DATA_DIRS} = '';
   is_deeply( [$conf->xdg_data_dirs()],
-             [ File::Spec->catdir($rootdir, qw/usr local share/),
+             [ File::Spec->catdir($rootdir, qw/@SHAREDIR_SPLIT@/),
+               File::Spec->catdir($rootdir, qw/usr local share/),
                File::Spec->catdir($rootdir, qw/usr share/)         ],
        'xdg_data_dirs default - OO');
 }
