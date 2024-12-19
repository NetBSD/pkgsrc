$NetBSD: patch-lib_Alien_Build_Plugin_PkgConfig_Negotiate.pm,v 1.2 2024/12/19 03:16:24 gutteridge Exp $

Don't assume pkgconfig won't work on 64-bit "Solaris" and prevent its use.

--- lib/Alien/Build/Plugin/PkgConfig/Negotiate.pm.orig	2024-10-29 00:51:50.000000000 +0000
+++ lib/Alien/Build/Plugin/PkgConfig/Negotiate.pm
@@ -48,7 +48,7 @@ sub pick
     # on solaris 64 bit.
     # Some advice on pkg-config and 64 bit Solaris
     # https://docs.oracle.com/cd/E53394_01/html/E61689/gplhi.html
-    my $is_solaris64 = (_perl_config('osname') eq 'solaris' && _perl_config('ptrsize') == 8);
+    my $is_solaris64 = 0; # (_perl_config('osname') eq 'solaris' && _perl_config('ptrsize') == 8);
 
     # PkgConfig.pm is more reliable on windows
     my $is_windows = _perl_config('osname') eq 'MSWin32';
