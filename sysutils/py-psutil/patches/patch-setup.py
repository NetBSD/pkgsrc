$NetBSD: patch-setup.py,v 1.1 2013/10/12 13:32:36 wiz Exp $

Port to NetBSD.

--- setup.py.orig	2013-06-17 10:35:09.000000000 +0000
+++ setup.py
@@ -108,6 +108,15 @@ elif sys.platform.startswith("freebsd"):
                             libraries=["devstat"],
                             ),
                   posix_extension]
+# NetBSD
+elif sys.platform.startswith("netbsd"):
+    extensions = [Extension('_psutil_netbsd',
+                            sources = ['psutil/_psutil_netbsd.c',
+                                       'psutil/_psutil_common.c',
+                                       'psutil/arch/netbsd/process_info.c'],
+                            libraries=[],
+                            ),
+                  posix_extension]
 # Linux
 elif sys.platform.startswith("linux"):
     extensions = [Extension('_psutil_linux',
