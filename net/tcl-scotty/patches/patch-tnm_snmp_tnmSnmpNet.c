$NetBSD: patch-tnm_snmp_tnmSnmpNet.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.
Avoid use of interp->result.

--- tnm/snmp/tnmSnmpNet.c.orig	1997-08-26 18:55:45.000000000 +0000
+++ tnm/snmp/tnmSnmpNet.c
@@ -170,7 +170,7 @@ straps(interp)
     Tcl_Interp *interp;
 {
     int *pidArray, argc = 1;
-    static char *argv[2] = { NULL, 0 };
+    static const char *argv[2] = { NULL, 0 };
     static Tcl_Channel channel = NULL;
     static char *straps = NULL;
 
@@ -1060,7 +1060,7 @@ ResponseProc(clientData, mask)
 	Tcl_BackgroundError(interp);
     }
     if (code == TCL_CONTINUE && hexdump) {
-	TnmWriteMessage(interp, interp->result);
+        TnmWriteMessage(interp, Tcl_GetStringResult(interp));
 	TnmWriteMessage(interp, "\n");
     }
 }
@@ -1102,7 +1102,7 @@ TrapProc(clientData, mask)
 	Tcl_BackgroundError(interp);
     }
     if (code == TCL_CONTINUE && hexdump) {
-	TnmWriteMessage(interp, interp->result);
+	TnmWriteMessage(interp, Tcl_GetStringResult(interp));
 	TnmWriteMessage(interp, "\n");
     }
 }
@@ -1147,7 +1147,7 @@ AgentProc(clientData, mask)
 	Tcl_BackgroundError(interp);
     }
     if (code == TCL_CONTINUE && hexdump) {
-	TnmWriteMessage(interp, interp->result);
+	TnmWriteMessage(interp, Tcl_GetStringResult(interp));
 	TnmWriteMessage(interp, "\n");
     }
 }
