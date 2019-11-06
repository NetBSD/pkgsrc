$NetBSD: patch-psutil___psbsd.py,v 1.5 2019/11/06 15:48:23 adam Exp $

Stop using SDEAD as it is no longer available.

--- psutil/_psbsd.py.orig	2019-06-28 13:13:13.000000000 +0000
+++ psutil/_psbsd.py
@@ -58,7 +58,7 @@ elif OPENBSD or NETBSD:
         # equivalent. Also it appears there's no equivalent of
         # psutil.STATUS_DEAD. SDEAD really means STATUS_ZOMBIE.
         # cext.SZOMB: _common.STATUS_ZOMBIE,
-        cext.SDEAD: _common.STATUS_ZOMBIE,
+        # cext.SDEAD: _common.STATUS_ZOMBIE,
         cext.SZOMB: _common.STATUS_ZOMBIE,
         # From http://www.eecs.harvard.edu/~margo/cs161/videos/proc.h.txt
         # OpenBSD has SRUN and SONPROC: SRUN indicates that a process
