$NetBSD: patch-radicale_storage.py,v 1.1 2017/07/06 03:12:48 darcy Exp $

Load vobject from vdirsyncer module 

--- radicale/storage.py.orig    2017-07-01 03:05:13.000000000 +0000
+++ radicale/storage.py
@@ -44,7 +44,7 @@ from random import getrandbits
 from tempfile import NamedTemporaryFile, TemporaryDirectory

 import pkg_resources
-import vobject
+import vdirsyncer.vobject

 if sys.version_info >= (3, 5):
     # HACK: Avoid import cycle for Python < 3.5
