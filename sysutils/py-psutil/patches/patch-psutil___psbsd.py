$NetBSD: patch-psutil___psbsd.py,v 1.9 2026/04/06 16:53:12 fox Exp $

Remove dependency on procfs.

Upstream: https://github.com/giampaolo/psutil/pull/2805

--- psutil/_psbsd.py.orig	2026-01-20 14:38:58.000000000 +0000
+++ psutil/_psbsd.py
@@ -135,27 +135,11 @@ kinfo_proc_map = dict(
 
 def virtual_memory():
     mem = cext.virtual_mem()
+    total, free, active, inactive, wired, cached, buffers, shared = mem
     if NETBSD:
-        total, free, active, inactive, wired, cached = mem
-        # On NetBSD buffers and shared mem is determined via /proc.
-        # The C ext set them to 0.
-        with open('/proc/meminfo', 'rb') as f:
-            for line in f:
-                if line.startswith(b'Buffers:'):
-                    buffers = int(line.split()[1]) * 1024
-                elif line.startswith(b'MemShared:'):
-                    shared = int(line.split()[1]) * 1024
-        # Before avail was calculated as (inactive + cached + free),
-        # same as zabbix, but it turned out it could exceed total (see
-        # #2233), so zabbix seems to be wrong. Htop calculates it
-        # differently, and the used value seem more realistic, so let's
-        # match htop.
-        # https://github.com/htop-dev/htop/blob/e7f447b/netbsd/NetBSDProcessList.c#L162
-        # https://github.com/zabbix/zabbix/blob/af5e0f8/src/libs/zbxsysinfo/netbsd/memory.c#L135
         used = active + wired
-        avail = total - used
-    else:
-        total, free, active, inactive, wired, cached, buffers, shared = mem
+        avail = total - used        
+    else:        
         # matches freebsd-memory CLI:
         # * https://people.freebsd.org/~rse/dist/freebsd-memory
         # * https://www.cyberciti.biz/files/scripts/freebsd-memory.pl.txt
@@ -260,24 +244,7 @@ def cpu_stats():
         # Note: the C ext is returning some metrics we are not exposing:
         # traps.
         ctxsw, intrs, soft_intrs, syscalls, _traps = cext.cpu_stats()
-    elif NETBSD:
-        # XXX
-        # Note about intrs: the C extension returns 0. intrs
-        # can be determined via /proc/stat; it has the same value as
-        # soft_intrs thought so the kernel is faking it (?).
-        #
-        # Note about syscalls: the C extension always sets it to 0 (?).
-        #
-        # Note: the C ext is returning some metrics we are not exposing:
-        # traps, faults and forks.
-        ctxsw, intrs, soft_intrs, syscalls, _traps, _faults, _forks = (
-            cext.cpu_stats()
-        )
-        with open('/proc/stat', 'rb') as f:
-            for line in f:
-                if line.startswith(b'intr'):
-                    intrs = int(line.split()[1])
-    elif OPENBSD:
+    elif NETBSD or OPENBSD:
         # Note: the C ext is returning some metrics we are not exposing:
         # traps, faults and forks.
         ctxsw, intrs, soft_intrs, syscalls, _traps, _faults, _forks = (
