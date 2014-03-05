$NetBSD: patch-tnm_generic_tnmNetdb.c,v 1.1 2014/03/05 13:52:29 he Exp $

Avoid use of interp->result.
Constify.

--- tnm/generic/tnmNetdb.c.orig	1998-09-23 16:47:43.000000000 +0200
+++ tnm/generic/tnmNetdb.c	2014-03-04 18:05:58.000000000 +0100
@@ -36,22 +36,22 @@
 
 static int
 NetdbHosts		_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 NetdbIp			_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 NetdbNetworks		_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 NetdbProtocols		_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 NetdbServices		_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 NetdbSunrpcs		_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 
 
 /*
@@ -75,7 +75,7 @@
 NetdbHosts(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     /*
      * Process the "netdb hosts" command option:
@@ -177,7 +177,7 @@
 NetdbIp(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     struct in_addr ipaddr;
     
@@ -289,7 +289,7 @@
 NetdbNetworks(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     /*
      * Process the "netdb networks" command option:
@@ -399,8 +399,10 @@
 NetdbProtocols(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
+    char res[20];
+
     /*
      * Process the "netdb protocols" command option:
      */
@@ -462,7 +464,8 @@
 			     (char *) NULL);
 	    return TCL_ERROR;
 	}
-	sprintf(interp->result, "%d", proto->p_proto);
+	sprintf(res, "%d", proto->p_proto);
+	Tcl_SetResult(interp, res, TCL_VOLATILE);
 	return TCL_OK;
     }
 
@@ -492,8 +495,10 @@
 NetdbServices(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
+    char res[20];
+
     /*
      * Process the "netdb services" command option:
      */
@@ -554,7 +559,8 @@
 	if (TnmSetIPPort(interp, argv[4], argv[3], &addr) != TCL_OK) {
 	    return TCL_ERROR;
 	}
-	sprintf(interp->result, "%d", ntohs(addr.sin_port));
+	sprintf(res, "%d", ntohs(addr.sin_port));
+	Tcl_SetResult(interp, res, TCL_VOLATILE);
 	return TCL_OK;
     }
 
@@ -584,8 +590,10 @@
 NetdbSunrpcs(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
+    char res[20];
+
     /*
      * Process the "netdb sunrpcs" command option:
      */
@@ -649,7 +657,8 @@
 			     (char *) NULL);
 	    return TCL_ERROR;
 	}
-	sprintf(interp->result, "%d", rpc->r_number);
+	sprintf(res, "%d", rpc->r_number);
+	Tcl_SetResult(interp, res, TCL_VOLATILE);
 	return TCL_OK;
     }
 
@@ -680,7 +689,7 @@
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     if (argc < 2) {
 	Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
