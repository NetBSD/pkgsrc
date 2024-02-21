$NetBSD: patch-agent_snmp__perl.c,v 1.2 2024/02/21 10:21:01 wiz Exp $

--- agent/snmp_perl.c.orig	2023-08-15 20:32:01.000000000 +0000
+++ agent/snmp_perl.c
@@ -4,6 +4,10 @@
 #include "perl.h"
 #pragma GCC diagnostic pop
 
+#ifdef U64TYPE
+#define U64 U64pairU32
+#endif
+
 #include <net-snmp/net-snmp-config.h>
 #include <net-snmp/net-snmp-includes.h>
 #include <net-snmp/agent/net-snmp-agent-includes.h>
