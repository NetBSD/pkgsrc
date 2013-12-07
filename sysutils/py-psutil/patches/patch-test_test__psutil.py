$NetBSD: patch-test_test__psutil.py,v 1.2 2013/12/07 21:25:24 richard Exp $

Port to NetBSD.

--- test/test_psutil.py.orig	2013-11-22 21:26:42.000000000 +0000
+++ test/test_psutil.py
@@ -77,7 +77,7 @@ POSIX = os.name == 'posix'
 LINUX = sys.platform.startswith("linux")
 WINDOWS = sys.platform.startswith("win32")
 OSX = sys.platform.startswith("darwin")
-BSD = sys.platform.startswith("freebsd")
+BSD = sys.platform.startswith("freebsd") or sys.platform.startswith("netbsd")
 SUNOS = sys.platform.startswith("sunos")
 VALID_PROC_STATUSES = [getattr(psutil, x) for x in dir(psutil)
                        if x.startswith('STATUS_')]
