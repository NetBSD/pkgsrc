$NetBSD: patch-psutil_____init____.py,v 1.3 2015/12/01 14:07:36 ryoon Exp $

--- psutil/__init__.py.orig	2015-11-25 01:20:34.000000000 +0000
+++ psutil/__init__.py
@@ -122,7 +122,7 @@ elif sys.platform.startswith("win32"):
 elif sys.platform.startswith("darwin"):
     from . import _psosx as _psplatform
 
-elif sys.platform.startswith("freebsd") or sys.platform.startswith("openbsd"):
+elif sys.platform.startswith("freebsd") or sys.platform.startswith("openbsd") or sys.platform.startswith("netbsd"):
     from . import _psbsd as _psplatform
 
 elif sys.platform.startswith("sunos"):
