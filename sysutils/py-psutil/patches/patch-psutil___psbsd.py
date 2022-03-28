$NetBSD: patch-psutil___psbsd.py,v 1.6 2022/03/28 21:50:43 wiz Exp $

Stop using SDEAD as it is no longer available.

--- psutil/_psbsd.py.orig	2021-12-15 09:34:00.000000000 +0000
+++ psutil/_psbsd.py
@@ -61,7 +61,7 @@ elif OPENBSD:
         # equivalent. Also it appears there's no equivalent of
         # psutil.STATUS_DEAD. SDEAD really means STATUS_ZOMBIE.
         # cext.SZOMB: _common.STATUS_ZOMBIE,
-        cext.SDEAD: _common.STATUS_ZOMBIE,
+        # cext.SDEAD: _common.STATUS_ZOMBIE,
         cext.SZOMB: _common.STATUS_ZOMBIE,
         # From http://www.eecs.harvard.edu/~margo/cs161/videos/proc.h.txt
         # OpenBSD has SRUN and SONPROC: SRUN indicates that a process
@@ -189,6 +189,8 @@ def virtual_memory():
                     buffers = int(line.split()[1]) * 1024
                 elif line.startswith(b'MemShared:'):
                     shared = int(line.split()[1]) * 1024
+                elif line.startswith(b'Cached:'):
+                    cached = int(line.split()[1]) * 1024
     avail = inactive + cached + free
     used = active + wired + cached
     percent = usage_percent((total - avail), total, round_=1)
