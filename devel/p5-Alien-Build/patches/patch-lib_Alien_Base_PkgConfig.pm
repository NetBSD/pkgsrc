$NetBSD: patch-lib_Alien_Base_PkgConfig.pm,v 1.1 2024/12/21 21:17:29 gutteridge Exp $

Don't assume pkgconfig won't work on 64-bit "Solaris" and prevent its use.

--- lib/Alien/Base/PkgConfig.pm.orig	2024-10-29 00:51:50.000000000 +0000
+++ lib/Alien/Base/PkgConfig.pm
@@ -129,7 +129,7 @@ sub pkg_config_command {
       # be abstracted so that it can be shared here and
       # in Build.PL
 
-      if (`pkg-config --version` && $? == 0 && !($^O eq 'solaris' && $Config{ptrsize} == 8)) {
+      if (`pkg-config --version` && $? == 0) {
         $pkg_config_command = 'pkg-config';
       } else {
         require PkgConfig;
