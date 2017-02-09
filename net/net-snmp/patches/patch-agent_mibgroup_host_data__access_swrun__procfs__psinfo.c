$NetBSD: patch-agent_mibgroup_host_data__access_swrun__procfs__psinfo.c,v 1.1 2017/02/09 09:33:57 maya Exp $

Fix compilation on Solaris 11.2, from upstream commit:
https://sourceforge.net/p/net-snmp/code/ci/e2ce8bb37819c9ae24d482ac4108772f7b2c9b8c/

--- agent/mibgroup/host/data_access/swrun_procfs_psinfo.c.orig	2014-12-08 20:23:22.000000000 +0000
+++ agent/mibgroup/host/data_access/swrun_procfs_psinfo.c
@@ -33,6 +33,10 @@
 #include <sys/proc.h>
 #endif
 
+#include <sys/processor.h>
+#include <sys/procset.h>
+#include <thread.h>
+
 #include <net-snmp/net-snmp-includes.h>
 #include <net-snmp/agent/net-snmp-agent-includes.h>
 #include <net-snmp/library/container.h>
