$NetBSD: patch-src_calibre_constants.py,v 1.1 2011/05/21 15:07:48 wiz Exp $

--- src/calibre/constants.py.orig	2011-05-13 17:49:55.000000000 +0000
+++ src/calibre/constants.py
@@ -27,7 +27,9 @@ iswindows = 'win32' in _plat or 'win64' 
 isosx     = 'darwin' in _plat
 isnewosx  = isosx and getattr(sys, 'new_app_bundle', False)
 isfreebsd = 'freebsd' in _plat
-islinux   = not(iswindows or isosx or isfreebsd)
+isnetbsd = 'netbsd' in _plat
+isbsd = isfreebsd or isnetbsd
+islinux   = not(iswindows or isosx or isbsd)
 isfrozen  = hasattr(sys, 'frozen')
 isunix = isosx or islinux
 
