$NetBSD: patch-setup.py,v 1.3 2013/12/07 21:25:24 richard Exp $

Port to NetBSD.

--- setup.py.orig	2013-11-20 19:29:05.000000000 +0000
+++ setup.py
@@ -122,6 +122,18 @@ elif sys.platform.startswith("freebsd"):
         libraries=["devstat"]),
         posix_extension,
     ]
+# NetBSD
+elif sys.platform.startswith("netbsd"):
+	extensions = [Extension(
+		'_psutil_netbsd',
+		sources = [
+			'psutil/_psutil_netbsd.c',
+			'psutil/_psutil_common.c',
+			'psutil/arch/netbsd/process_info.c'
+		],
+		libraries=[]),
+		posix_extension,
+	]
 # Linux
 elif sys.platform.startswith("linux"):
     extensions = [Extension(
