$NetBSD: patch-salt_grains_core.py,v 1.9 2026/02/26 17:40:44 khorben Exp $

Fix starting Salt on NetBSD and OpenBSD.

--- salt/grains/core.py.orig	2026-02-26 17:34:46.201241607 +0000
+++ salt/grains/core.py
@@ -2784,7 +2784,7 @@ def os_data():
         grains["osfullname"] = "{} {}".format(grains["kernel"], grains["osrelease"])
         grains.update(_bsd_cpudata(grains))
     elif grains["kernel"] in ("OpenBSD", "NetBSD"):
-        grains["os_family"] = grains["os"] = grains["kernel"]
+        grains["os_family"] = grains["osfullname"] = grains["os"] = grains["kernel"]
         grains.update(_bsd_cpudata(grains))
         grains["osrelease"] = grains["kernelrelease"].split("-")[0]
         grains["osfullname"] = "{} {}".format(grains["kernel"], grains["osrelease"])
