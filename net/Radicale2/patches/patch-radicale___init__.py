$NetBSD: patch-radicale___init__.py,v 1.1 2017/07/06 03:12:48 darcy Exp $

Load vobject from vdirsyncer module

--- radicale/__init__.py.orig   2017-07-01 03:05:13.000000000 +0000
+++ radicale/__init__.py
@@ -48,7 +48,7 @@ from http import client
 from urllib.parse import unquote, urlparse
 from xml.etree import ElementTree as ET

-import vobject
+import vdirsyncer.vobject

 from . import auth, rights, storage, web, xmlutils
