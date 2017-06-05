$NetBSD: patch-sim_ppc_emul_netbsd.c,v 1.1 2017/06/05 10:41:28 maya Exp $

time_t conversion compatibility, experimental.
Please correct the naming, thank you.

--- sim/ppc/emul_netbsd.c.orig	2014-06-11 16:34:42.000000000 +0000
+++ sim/ppc/emul_netbsd.c
@@ -118,6 +118,7 @@ extern int errno;
 
 #if WITH_NetBSD_HOST
 #define SYS(X) ASSERT(call == (SYS_##X))
+#define SYSSYS(X) ASSERT(call == (SYS___##X50))
 #else
 #define SYS(X)
 #endif
@@ -737,7 +738,11 @@ do_gettimeofday(os_emul_data *emul,
   if (WITH_TRACE && ppc_trace[trace_os_emul])
     printf_filtered ("0x%lx, 0x%lx", (long)t_addr, (long)tz_addr);
 
+#if 0
   SYS(gettimeofday);
+#else
+  SYS___gettimeofday50;
+#endif
   emul_write_status(processor, status, err);
   if (status == 0) {
     if (t_addr != 0)
@@ -767,7 +772,11 @@ do_getrusage(os_emul_data *emul,
   if (WITH_TRACE && ppc_trace[trace_os_emul])
     printf_filtered ("%d, 0x%lx", who, (long)rusage_addr);
 
+#if 0
   SYS(getrusage);
+#else
+  SYS___getrusage50;
+#endif
   emul_write_status(processor, status, err);
   if (status == 0) {
     if (rusage_addr != 0)
