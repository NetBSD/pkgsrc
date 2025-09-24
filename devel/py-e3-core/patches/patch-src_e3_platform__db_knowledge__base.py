$NetBSD: patch-src_e3_platform__db_knowledge__base.py,v 1.1 2025/09/24 05:36:17 dkazankov Exp $

Fix NetBSD support

--- src/e3/platform_db/knowledge_base.py.orig	2025-03-28 15:21:34.000000000 +0200
+++ src/e3/platform_db/knowledge_base.py
@@ -167,13 +167,13 @@
     "ppc-aix": {"os": "AIX", "cpu": None},
     "x86_64-darwin": {"os": "Darwin", "cpu": "i386"},
     "x86-freebsd": {"os": "FreeBSD", "cpu": "i386"},
-    "x86-openbsd": {"os": "OpenBSD", "cpu": None},
-    "x86-netbsd": {"os": "NetBSD", "cpu": None},
-    "x86-dragonfly": {"os": "DragonFly", "cpu": None},
+    "x86-openbsd": {"os": "OpenBSD", "cpu": "i.86"},
+    "x86-netbsd": {"os": "NetBSD", "cpu": "i.86"},
+    "x86-dragonfly": {"os": "DragonFly", "cpu": "i386"},
     "x86_64-freebsd": {"os": "FreeBSD", "cpu": "amd64"},
-    "x86_64-openbsd": {"os": "OpenBSD", "cpu": None},
-    "x86_64-netbsd": {"os": "NetBSD", "cpu": None},
-    "x86_64-dragonfly": {"os": "DragonFly", "cpu": None},
+    "x86_64-openbsd": {"os": "OpenBSD", "cpu": "amd64|x86_64"},
+    "x86_64-netbsd": {"os": "NetBSD", "cpu": "amd64|x86_64"},
+    "x86_64-dragonfly": {"os": "DragonFly", "cpu": "amd64"},
     "ppc-linux": {"os": "Linux", "cpu": "powerpc.*|ppc64"},
     "x86-linux": {"os": "Linux", "cpu": "i.86|pentium"},
     "x86_64-linux": {"os": "Linux", "cpu": "x86_64"},
