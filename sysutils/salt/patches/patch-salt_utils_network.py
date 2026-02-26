$NetBSD: patch-salt_utils_network.py,v 1.9 2026/02/26 17:40:44 khorben Exp $

Avoid crashes on NetBSD in the OS version check when the part after "_"
is unknown to Version(). (e.g., "STABLE" as opposed to "BETA")

--- salt/utils/network.py.orig	2025-12-18 09:42:02.000000000 +0000
+++ salt/utils/network.py
@@ -1099,7 +1099,7 @@ def netbsd_interfaces():
     address)
     """
     # NetBSD versions prior to 8.0 can still use linux_interfaces()
-    if Version(os.uname()[2]) < Version("8.0"):
+    if Version(os.uname()[2].split('_')[0]) < Version("8.0"):
         return linux_interfaces()
 
     ifconfig_path = salt.utils.path.which("ifconfig")
