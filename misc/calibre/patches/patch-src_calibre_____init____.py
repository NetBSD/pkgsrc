$NetBSD: patch-src_calibre_____init____.py,v 1.1 2011/05/21 15:07:48 wiz Exp $

--- src/calibre/__init__.py.orig	2011-05-13 17:49:55.000000000 +0000
+++ src/calibre/__init__.py
@@ -13,6 +13,7 @@ warnings.simplefilter('ignore', Deprecat
 
 
 from calibre.constants import (iswindows, isosx, islinux, isfreebsd, isfrozen,
+			      isnetbsd, isbsd,
                               preferred_encoding, __appname__, __version__, __author__,
                               win32event, win32api, winerror, fcntl,
                               filesystem_encoding, plugins, config_dir)
