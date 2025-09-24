$NetBSD: patch-src_e3_os_platform.py,v 1.1 2025/09/24 05:36:17 dkazankov Exp $

Add NetBSD support

--- src/e3/os/platform.py.orig	2025-03-28 15:21:34.000000000 +0200
+++ src/e3/os/platform.py
@@ -165,7 +165,7 @@
 
         if system == "Darwin":  # darwin-only
             version = cls.uname.release
-        elif system == "FreeBSD":  # bsd-only
+        elif system == "FreeBSD" or system == "NetBSD":  # bsd-only
             version = re.sub("-.*", "", cls.uname.release)
         elif system == "Linux":  # linux-only
             full_version_number = cls.ld_info["version"]
