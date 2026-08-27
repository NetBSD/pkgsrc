$NetBSD: patch-base_g.py,v 1.1 2026/08/27 09:39:59 wiz Exp $

Adapt to Python 3.12 changes.

--- base/g.py.orig	2026-08-27 09:35:41.282305902 +0000
+++ base/g.py
@@ -128,7 +128,7 @@ class ConfigBase(object):
             try:
                 fp = open(self.filename, "r")
                 try:
-                    self.conf.readfp(fp)
+                    self.conf.read_file(fp, self.filename)
                 except configparser.MissingSectionHeaderError:
                     print("")
                     log.error("Found No Section in %s. Please set the http proxy for root and try again." % self.filename)
