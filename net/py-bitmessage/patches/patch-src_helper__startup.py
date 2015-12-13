$NetBSD: patch-src_helper__startup.py,v 1.1 2015/12/13 00:31:54 kamil Exp $

Unbreak version check of all BSDs.

Merged upstream:
https://github.com/Bitmessage/PyBitmessage/pull/811

--- src/helper_startup.py.orig	2014-10-15 21:16:27.000000000 +0000
+++ src/helper_startup.py
@@ -140,8 +140,8 @@ def loadConfig():
 
 def isOurOperatingSystemLimitedToHavingVeryFewHalfOpenConnections():
     try:
-        VER_THIS=StrictVersion(platform.version())
         if sys.platform[0:3]=="win":
+            VER_THIS=StrictVersion(platform.version())
             return StrictVersion("5.1.2600")<=VER_THIS and StrictVersion("6.0.6000")>=VER_THIS
         return False
     except Exception as err:
