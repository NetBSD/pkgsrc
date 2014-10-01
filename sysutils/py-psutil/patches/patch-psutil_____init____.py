$NetBSD: patch-psutil_____init____.py,v 1.2 2014/10/01 11:53:33 wiz Exp $

Port to NetBSD.

--- psutil/__init__.py.orig	2014-07-15 15:23:11.000000000 +0000
+++ psutil/__init__.py
@@ -150,6 +150,9 @@ elif sys.platform.startswith("darwin"):
 elif sys.platform.startswith("freebsd"):
     import psutil._psbsd as _psplatform
 
+elif sys.platform.startswith("netbsd"):
+    import psutil._psnetbsd as _psplatform
+
 elif sys.platform.startswith("sunos"):
     import psutil._pssunos as _psplatform
     from psutil._pssunos import (CONN_IDLE,  # NOQA
