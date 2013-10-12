$NetBSD: patch-psutil_____init____.py,v 1.1 2013/10/12 13:32:36 wiz Exp $

Port to NetBSD.

--- psutil/__init__.py.orig	2013-07-12 15:34:08.000000000 +0000
+++ psutil/__init__.py
@@ -97,6 +97,9 @@ elif sys.platform.startswith("darwin"):
 elif sys.platform.startswith("freebsd"):
     import psutil._psbsd as _psplatform
 
+elif sys.platform.startswith("netbsd"):
+    import psutil._psnetbsd as _psplatform
+
 elif sys.platform.startswith("sunos"):
     import psutil._pssunos as _psplatform
     from psutil._pssunos import (CONN_IDLE,
