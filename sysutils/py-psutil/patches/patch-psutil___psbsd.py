$NetBSD: patch-psutil___psbsd.py,v 1.7 2022/03/28 21:57:36 wiz Exp $

Fix reporting of cached memory on NetBSD.
https://github.com/giampaolo/psutil/pull/2088

--- psutil/_psbsd.py.orig	2021-12-15 09:34:00.000000000 +0000
+++ psutil/_psbsd.py
@@ -189,6 +189,8 @@ def virtual_memory():
                     buffers = int(line.split()[1]) * 1024
                 elif line.startswith(b'MemShared:'):
                     shared = int(line.split()[1]) * 1024
+                elif line.startswith(b'Cached:'):
+                    cached = int(line.split()[1]) * 1024
     avail = inactive + cached + free
     used = active + wired + cached
     percent = usage_percent((total - avail), total, round_=1)
