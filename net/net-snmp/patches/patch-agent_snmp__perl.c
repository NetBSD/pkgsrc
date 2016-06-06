$NetBSD: patch-agent_snmp__perl.c,v 1.1 2016/06/06 14:11:35 he Exp $

--- agent/snmp_perl.c.orig	2014-12-08 20:23:22.000000000 +0000
+++ agent/snmp_perl.c
@@ -5,6 +5,10 @@
 #include <EXTERN.h>
 #include "perl.h"
 
+#ifdef U64TYPE
+#define U64 U64pairU32
+#endif
+
 #include <net-snmp/net-snmp-config.h>
 #include <net-snmp/net-snmp-includes.h>
 #include <net-snmp/agent/net-snmp-agent-includes.h>
