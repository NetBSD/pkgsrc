$NetBSD: patch-setup.py,v 1.4 2015/12/01 14:07:37 ryoon Exp $

Port to NetBSD.

--- setup.py.orig	2015-11-25 01:20:34.000000000 +0000
+++ setup.py
@@ -151,6 +151,19 @@ elif sys.platform.startswith("openbsd"):
         define_macros=[VERSION_MACRO],
         libraries=["kvm"])
     extensions = [ext, posix_extension]
+# NetBSD
+elif sys.platform.startswith("netbsd"):
+    ext = Extension(
+        'psutil._psutil_bsd',
+        sources=[
+            'psutil/_psutil_bsd.c',
+            'psutil/_psutil_common.c',
+            'psutil/arch/bsd/netbsd.c',
+            'psutil/arch/bsd/netbsd_socks.c',
+        ],
+        define_macros=[VERSION_MACRO],
+        libraries=["kvm"])
+    extensions = [ext, posix_extension]
 # Linux
 elif sys.platform.startswith("linux"):
     def get_ethtool_macro():
