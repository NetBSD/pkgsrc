$NetBSD: patch-setup.py,v 1.2 2013/11/02 09:38:34 wiz Exp $

Port to NetBSD.

--- setup.py.orig	2013-10-22 18:12:21.000000000 +0000
+++ setup.py
@@ -145,6 +145,18 @@ elif sys.platform.startswith("freebsd"):
         libraries=["devstat"]),
         posix_extension,
     ]
+# NetBSD
+elif sys.platform.startswith("netbsd"):
+    extensions = [Extension(
+        '_psutil_netbsd',
+        sources = [
+            'psutil/_psutil_netbsd.c',
+            'psutil/_psutil_common.c',
+            'psutil/arch/netbsd/process_info.c'
+        ],
+        libraries=[]),
+        posix_extension,
+    ]
 # Linux
 elif sys.platform.startswith("linux"):
     kernel_ver = get_kernel_version()
