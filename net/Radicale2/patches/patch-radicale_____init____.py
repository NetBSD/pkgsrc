$NetBSD: patch-radicale_____init____.py,v 1.1 2026/09/13 13:07:39 jakllsch Exp $

Avoid using deprecated and removed pkg_resources

--- radicale/__init__.py.orig	2026-09-12 21:09:52.972762254 +0000
+++ radicale/__init__.py
@@ -33,7 +33,7 @@ import io
 import itertools
 import logging
 import os
-import pkg_resources
+from importlib.metadata import version
 import posixpath
 import pprint
 import random
@@ -54,7 +54,7 @@ import vobject
 from radicale import auth, config, log, rights, storage, web, xmlutils
 
 
-VERSION = pkg_resources.get_distribution('radicale').version
+VERSION = version('radicale')
 
 NOT_ALLOWED = (
     client.FORBIDDEN, (("Content-Type", "text/plain"),),
