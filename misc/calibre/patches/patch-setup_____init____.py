$NetBSD: patch-setup_____init____.py,v 1.1 2011/05/21 15:07:48 wiz Exp $

--- setup/__init__.py.orig	2011-05-20 14:41:31.000000000 +0000
+++ setup/__init__.py
@@ -12,7 +12,9 @@ is64bit = platform.architecture()[0] == 
 iswindows = re.search('win(32|64)', sys.platform)
 isosx = 'darwin' in sys.platform
 isfreebsd = 'freebsd' in sys.platform
-islinux = not isosx and not iswindows and not isfreebsd
+isnetbsd = 'netbsd' in sys.platform
+isbsd = isnetbsd or isfreebsd
+islinux = not isosx and not iswindows and not isbsd
 SRC = os.path.abspath('src')
 sys.path.insert(0, SRC)
 sys.resources_location = os.path.join(os.path.dirname(SRC), 'resources')
