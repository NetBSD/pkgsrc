$NetBSD: patch-test_test__psutil.py,v 1.1 2013/10/12 13:32:36 wiz Exp $

Port to NetBSD.

--- test/test_psutil.py.orig	2013-07-10 14:02:21.000000000 +0000
+++ test/test_psutil.py
@@ -62,7 +62,7 @@ POSIX = os.name == 'posix'
 LINUX = sys.platform.startswith("linux")
 WINDOWS = sys.platform.startswith("win32")
 OSX = sys.platform.startswith("darwin")
-BSD = sys.platform.startswith("freebsd")
+BSD = sys.platform.startswith("freebsd") or sys.platform.startswith("netbsd")
 SUNOS = sys.platform.startswith("sunos")
 
 
