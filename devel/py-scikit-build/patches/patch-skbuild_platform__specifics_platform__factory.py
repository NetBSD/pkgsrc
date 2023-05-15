$NetBSD: patch-skbuild_platform__specifics_platform__factory.py,v 1.3 2023/05/15 20:57:36 adam Exp $

Add SunOS support.

--- skbuild/platform_specifics/platform_factory.py.orig	2020-02-02 00:00:00.000000000 +0000
+++ skbuild/platform_specifics/platform_factory.py
@@ -35,7 +35,7 @@ def get_platform() -> abstract.CMakePlat
 
         return osx.OSXPlatform()
 
-    if this_platform in {"freebsd", "netbsd", "os400", "openbsd"}:
+    if this_platform in {"freebsd", "netbsd", "os400", "openbsd", "sunos"}:
         from . import bsd
 
         return bsd.BSDPlatform()
