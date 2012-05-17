$NetBSD: patch-agent_mibgroup_agent_extend.c,v 1.1 2012/05/17 12:56:17 spz Exp $

patch by Jan Safranek <jsafranek@users.sourceforge.net> for CVE-2012-2141
from https://bugzilla.redhat.com/attachment.cgi?id=580443 :

Check out-of-index conditions in ExtendOutput2Table.

--- agent/mibgroup/agent/extend.c.orig	2010-07-08 11:19:15.000000000 +0000
+++ agent/mibgroup/agent/extend.c
@@ -1309,6 +1309,10 @@ handle_nsExtendOutput2Table(netsnmp_mib_
                  * Determine which line we've been asked for....
                  */
                 line_idx = *table_info->indexes->next_variable->val.integer;
+                if (line_idx < 1 || line_idx > extension->numlines) {
+                    netsnmp_set_request_error(reqinfo, request, SNMP_NOSUCHINSTANCE);
+                    continue;
+                }
                 cp  = extension->lines[line_idx-1];
 
                 /* 
