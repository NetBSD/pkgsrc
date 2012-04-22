$NetBSD: patch-src_calibre_constants.py,v 1.3 2012/04/22 19:33:01 gls Exp $

Make it recognize DragonFlyBSD

--- src/calibre/constants.py.orig	2012-04-13 04:21:01.000000000 +0000
+++ src/calibre/constants.py
@@ -28,7 +28,8 @@ isosx     = 'darwin' in _plat
 isnewosx  = isosx and getattr(sys, 'new_app_bundle', False)
 isfreebsd = 'freebsd' in _plat
 isnetbsd = 'netbsd' in _plat
-isbsd = isfreebsd or isnetbsd
+isdragonflybsd = 'dragonfly' in _plat
+isbsd = isfreebsd or isnetbsd or isdragonflybsd
 islinux   = not(iswindows or isosx or isbsd)
 isfrozen  = hasattr(sys, 'frozen')
 isunix = isosx or islinux
