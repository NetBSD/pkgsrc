$NetBSD: patch-setup.py,v 1.1 2024/10/13 15:04:05 wiz Exp $

Allow Python 3.13.
https://github.com/jazzband/geojson/commit/c13afff339e6b78f442785cc95f0eb66ddab3e7b

--- setup.py.orig	2024-10-13 15:02:21.044846161 +0000
+++ setup.py
@@ -17,8 +17,8 @@ else:
 
 
 major_version, minor_version = sys.version_info[:2]
-if not (major_version == 3 and 7 <= minor_version <= 12):
-    sys.stderr.write("Sorry, only Python 3.7 - 3.12 are "
+if not (major_version == 3 and 7 <= minor_version <= 13):
+    sys.stderr.write("Sorry, only Python 3.7 - 3.13 are "
                      "supported at this time.\n")
     exit(1)
 
@@ -53,6 +53,7 @@ setup(
         "Programming Language :: Python :: 3.10",
         "Programming Language :: Python :: 3.11",
         "Programming Language :: Python :: 3.12",
+        "Programming Language :: Python :: 3.13",
         "Topic :: Scientific/Engineering :: GIS",
     ]
 )
