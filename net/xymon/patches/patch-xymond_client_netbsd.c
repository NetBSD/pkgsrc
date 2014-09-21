$NetBSD: patch-xymond_client_netbsd.c,v 1.2 2014/09/21 14:49:45 spz Exp $

--- xymond/client/netbsd.c.orig	2012-07-14 16:32:11.000000000 +0000
+++ xymond/client/netbsd.c
@@ -24,6 +24,7 @@ void handle_netbsd_client(char *hostname
 	char *psstr;
 	char *topstr;
 	char *dfstr;
+	char *inodestr;
 	char *meminfostr;
 	char *msgsstr;
 	char *netstatstr;
@@ -47,6 +48,7 @@ void handle_netbsd_client(char *hostname
 	psstr = getdata("ps");
 	topstr = getdata("top");
 	dfstr = getdata("df");
+	inodestr = getdata("inode");
 	meminfostr = getdata("meminfo");
 	msgsstr = getdata("msgsstr");
 	netstatstr = getdata("netstat");
@@ -57,6 +59,7 @@ void handle_netbsd_client(char *hostname
 	unix_cpu_report(hostname, clienttype, os, hinfo, fromline, timestr, uptimestr, clockstr, msgcachestr, 
 			whostr, 0, psstr, 0, topstr);
 	unix_disk_report(hostname, clienttype, os, hinfo, fromline, timestr, "Avail", "Capacity", "Mounted", dfstr);
+	unix_inode_report(hostname, clienttype, os, hinfo, fromline, timestr, "iAvail", "%iCap", "Mounted", inodestr);
 	unix_procs_report(hostname, clienttype, os, hinfo, fromline, timestr, "COMMAND", NULL, psstr);
 	unix_ports_report(hostname, clienttype, os, hinfo, fromline, timestr, 3, 4, 5, portsstr);
 
