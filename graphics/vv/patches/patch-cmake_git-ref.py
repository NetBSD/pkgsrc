$NetBSD: patch-cmake_git-ref.py,v 1.2 2026/07/13 14:43:11 wiz Exp $

Pass in commit id.
Refused by upstream.
https://github.com/wolfpld/moderncore/issues/5

--- cmake/git-ref.py.orig	2026-07-04 20:57:10.000000000 +0000
+++ cmake/git-ref.py
@@ -3,14 +3,21 @@ import os
 import filecmp
 import subprocess
 import os
+import sys
 
 out = "GitRef.hpp"
 tmp = f"{out}.tmp"
 
-try:
-    ref = subprocess.run(["git", "rev-parse", "--short", "HEAD"], check=True, capture_output=True).stdout.decode().strip()
-except subprocess.CalledProcessError:
-    ref = "unknown"
+filename = sys.argv[1] if len(sys.argv) > 1 else None
+if filename and os.path.exists(filename):
+    with open(filename, "r") as fh:
+        for line in fh:
+            ref = line.rstrip()
+else:
+    try:
+        ref = subprocess.run(["git", "rev-parse", "--short", "HEAD"], check=True, capture_output=True).stdout.decode().strip()
+    except subprocess.CalledProcessError:
+        ref = "unknown"
 
 if not os.path.exists(out):
     with open(out, "w") as f:
