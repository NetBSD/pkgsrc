$NetBSD: patch-platforms_netbsd_hax__entry.c,v 1.1 2019/02/19 13:49:15 kamil Exp $

Correct retrieving CPU index.

--- platforms/netbsd/hax_entry.c.orig	2019-02-14 08:45:35.000000000 +0000
+++ platforms/netbsd/hax_entry.c
@@ -33,6 +33,7 @@
 #include <sys/conf.h>
 #include <sys/device.h>
 #include <sys/module.h>
+#include <sys/cpu.h>
 
 #include "../../core/include/config.h"
 #include "../../core/include/hax_core_interface.h"
@@ -230,7 +231,7 @@ haxm_modcmd(modcmd_t cmd, void *arg __un
         for (CPU_INFO_FOREACH(cii, ci)) {
             ++max_cpus;
             if (!ISSET(ci->ci_schedstate.spc_flags, SPCF_OFFLINE)) {
-                cpu_online_map |= __BIT(ci->ci_cpuid);
+                cpu_online_map |= __BIT(cpu_index(ci));
             }
         }
 
