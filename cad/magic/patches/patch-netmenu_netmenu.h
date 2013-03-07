$NetBSD: patch-netmenu_netmenu.h,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- netmenu/netmenu.h.orig	2013-03-02 22:53:01.000000000 +0000
+++ netmenu/netmenu.h
@@ -32,12 +32,7 @@
 
 extern void NMinit();
 extern void NMUnsetCell();
-extern int NMNewNetlist();
-extern int NMWriteNetlist();
 extern char *NMAddTerm();
-extern int NMDeleteTerm();
-extern int NMJoinNets();
-extern int NMDeleteNet();
 extern int NMEnumNets();
 extern int NMEnumTerms();
 extern char *NMNthNet();
@@ -47,6 +42,11 @@ extern bool NMHasList();
 extern void NMFlushNetlist();
 extern char *NMNetlistName();
 
+void NMJoinNets(char *termA, char *termB);
+void NMDeleteNet(char *net);
+void NMNewNetlist(char *name);
+void NMWriteNetlist(char *fileName);
+
 /* button functions, now exported to the command-line "netlist" command */
 extern void NMButtonLeft();
 extern void NMButtonMiddle();
