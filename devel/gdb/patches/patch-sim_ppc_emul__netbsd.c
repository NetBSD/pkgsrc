$NetBSD: patch-sim_ppc_emul__netbsd.c,v 1.1 2022/12/06 09:45:51 he Exp $

Use the correctly named versioned syscalls.

--- sim/ppc/emul_netbsd.c.orig	2020-10-24 04:23:02.000000000 +0000
+++ sim/ppc/emul_netbsd.c
@@ -783,7 +783,7 @@ do_gettimeofday(os_emul_data *emul,
   if (WITH_TRACE && ppc_trace[trace_os_emul])
     printf_filtered ("0x%lx, 0x%lx", (long)t_addr, (long)tz_addr);
 
-  SYS(gettimeofday);
+  SYS(__gettimeofday50);
   emul_write_status(processor, status, err);
   if (status == 0) {
     if (t_addr != 0)
@@ -813,7 +813,7 @@ do_getrusage(os_emul_data *emul,
   if (WITH_TRACE && ppc_trace[trace_os_emul])
     printf_filtered ("%d, 0x%lx", who, (long)rusage_addr);
 
-  SYS(getrusage);
+  SYS(__getrusage50);
   emul_write_status(processor, status, err);
   if (status == 0) {
     if (rusage_addr != 0)
