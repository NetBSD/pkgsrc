$NetBSD: patch-test_test__psutil.py,v 1.4 2015/12/01 14:07:37 ryoon Exp $

Port to NetBSD.

--- test/test_psutil.py.orig	2015-11-25 01:20:34.000000000 +0000
+++ test/test_psutil.py
@@ -107,7 +107,8 @@ LINUX = sys.platform.startswith("linux")
 OSX = sys.platform.startswith("darwin")
 FREEBSD = sys.platform.startswith("freebsd")
 OPENBSD = sys.platform.startswith("openbsd")
-BSD = FREEBSD or OPENBSD
+NETBSD = sys.platform.startswith("netbsd")
+BSD = FREEBSD or OPENBSD or NETBSD
 SUNOS = sys.platform.startswith("sunos")
 VALID_PROC_STATUSES = [getattr(psutil, x) for x in dir(psutil)
                        if x.startswith('STATUS_')]
