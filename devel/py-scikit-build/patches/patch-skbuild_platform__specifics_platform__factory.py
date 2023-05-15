$NetBSD: patch-skbuild_platform__specifics_platform__factory.py,v 1.2 2023/05/15 09:19:04 jperkin Exp $

Add NetBSD support
https://github.com/scikit-build/scikit-build/issues/971

--- skbuild/platform_specifics/platform_factory.py.orig	2023-05-05 18:58:16.000000000 +0000
+++ skbuild/platform_specifics/platform_factory.py
@@ -34,7 +34,7 @@ def get_platform() -> abstract.CMakePlat
 
         return osx.OSXPlatform()
 
-    if this_platform in {"freebsd", "os400", "openbsd"}:
+    if this_platform in {"freebsd", "netbsd", "os400", "openbsd", "sunos"}:
         from . import bsd
 
         return bsd.BSDPlatform()
