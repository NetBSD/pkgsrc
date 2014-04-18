$NetBSD: patch-test_test__psutil.py,v 1.3 2014/04/18 19:58:46 wiz Exp $

Port to NetBSD.

--- test/test_psutil.py.orig	2014-04-08 00:03:00.000000000 +0000
+++ test/test_psutil.py
@@ -87,7 +87,7 @@ if WINDOWS:
     WIN_VISTA = (6, 0, 0)
 LINUX = sys.platform.startswith("linux")
 OSX = sys.platform.startswith("darwin")
-BSD = sys.platform.startswith("freebsd")
+BSD = sys.platform.startswith("freebsd") or sys.platform.startswith("netbsd")
 SUNOS = sys.platform.startswith("sunos")
 VALID_PROC_STATUSES = [getattr(psutil, x) for x in dir(psutil)
                        if x.startswith('STATUS_')]
