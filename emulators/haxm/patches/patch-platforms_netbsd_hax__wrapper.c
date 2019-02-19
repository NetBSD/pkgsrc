$NetBSD: patch-platforms_netbsd_hax__wrapper.c,v 1.1 2019/02/19 13:49:15 kamil Exp $

Correct retrieving CPU index.

--- platforms/netbsd/hax_wrapper.c.orig	2019-02-14 08:45:35.000000000 +0000
+++ platforms/netbsd/hax_wrapper.c
@@ -35,6 +35,7 @@
 #include <sys/mutex.h>
 #include <sys/systm.h>
 #include <sys/xcall.h>
+#include <sys/cpu.h>
 #include <machine/cpu.h>
 #include <machine/cpufunc.h>
 
@@ -61,7 +62,7 @@ int hax_log_level(int level, const char 
 
 uint32_t hax_cpuid(void)
 {
-    return curcpu()->ci_cpuid;
+    return cpu_index(curcpu());
 }
 
 typedef struct smp_call_parameter {
