$NetBSD: patch-tnm_generic_tnmUdp.c,v 1.1 2014/03/05 13:52:29 he Exp $

Correct typo.
Constify.

--- tnm/generic/tnmUdp.c.orig	2000-07-06 11:47:02.000000000 +0200
+++ tnm/generic/tnmUdp.c	2014-03-04 15:49:15.000000000 +0100
@@ -40,33 +40,33 @@
 UdpEventProc	_ANSI_ARGS_((ClientData clientData, int mask));
 
 static Socket*
-UdpSocket	_ANSI_ARGS_((Tcl_Interp *interp, char *fileId));
+UdpSocket	_ANSI_ARGS_((Tcl_Interp *interp, const char *fileId));
 
 static int
-UdpOpen		_ANSI_ARGS_((Tcl_Interp *interp, int argc, char **argv));
+UdpOpen		_ANSI_ARGS_((Tcl_Interp *interp, int argc, const char **argv));
 
 static int
-UdpConnect	_ANSI_ARGS_((Tcl_Interp *interp, int argc, char **argv));
+UdpConnect	_ANSI_ARGS_((Tcl_Interp *interp, int argc, const char **argv));
 
 static int
-UdpSend		_ANSI_ARGS_((Tcl_Interp *interp, int argc, char **argv));
+UdpSend		_ANSI_ARGS_((Tcl_Interp *interp, int argc, const char **argv));
 
 static int
-UdpReceive	_ANSI_ARGS_((Tcl_Interp *interp, int argc, char **argv));
+UdpReceive	_ANSI_ARGS_((Tcl_Interp *interp, int argc, const char **argv));
 
 static int
-UdpClose	_ANSI_ARGS_((Tcl_Interp *interp, int argc, char **argv));
+UdpClose	_ANSI_ARGS_((Tcl_Interp *interp, int argc, const char **argv));
 
 #ifdef HAVE_MULTICAST
 static int
-UdpMulticast	_ANSI_ARGS_((Tcl_Interp *interp, int argc, char **argv));
+UdpMulticast	_ANSI_ARGS_((Tcl_Interp *interp, int argc, const char **argv));
 #endif
 
 static int
-UdpInfo		_ANSI_ARGS_((Tcl_Interp *interp, int argc, char **argv));
+UdpInfo		_ANSI_ARGS_((Tcl_Interp *interp, int argc, const char **argv));
 
 static int
-UdpBind		_ANSI_ARGS_((Tcl_Interp *interp, int argc, char **argv));
+UdpBind		_ANSI_ARGS_((Tcl_Interp *interp, int argc, const char **argv));
 
 /*
  * Procedure to be called by the event dispatcher whenever a UDP 
@@ -111,7 +111,7 @@
 static Socket *
 UdpSocket(interp, name)
     Tcl_Interp *interp;
-    char *name;
+    const char *name;
 {
     Tcl_HashEntry *entryPtr;
     Socket *usock;
@@ -136,12 +136,12 @@
 UdpOpen(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     int sock, isNew, code;
     struct sockaddr_in name;
     Socket *usock;
-    char *port = "0";
+    const char *port = "0";
     Tcl_HashEntry *entryPtr;
 
     if (argc < 2 || argc > 3) {
@@ -200,7 +200,7 @@
 UdpConnect(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     int sock, isNew;
     Socket *usock;
@@ -259,7 +259,7 @@
 UdpSend(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     struct sockaddr_in name;
     Socket *usock;
@@ -333,7 +333,7 @@
 UdpReceive(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     Socket *usock;
     int sock;
@@ -403,7 +403,7 @@
 UdpClose(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     Tcl_HashEntry *entryPtr;
     Socket *usock;
@@ -454,7 +454,7 @@
 UdpInfo(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     Socket *usock;
 
@@ -476,7 +476,7 @@
 	}
 
     } else {
-	
+        char res[128];
 	int sock, rc;
 	struct sockaddr_in server;
 	int length = sizeof(server);
@@ -489,15 +489,17 @@
 
 	rc = getsockname(sock, (struct sockaddr *) &server, &length);
 	if (rc == 0) {
-	    sprintf(interp->result, "%s %d ", 
+	    sprintf(res, "%s %d ", 
 		    inet_ntoa(server.sin_addr), 
 		    (int) ntohs(server.sin_port));
+	    Tcl_SetResult(interp, res, TCL_VOLATILE);
 	} else {
-	    sprintf(interp->result, "{} {} ");
+	    Tcl_SetResult(interp, "{} {} ", TCL_STATIC);
 	}
-	sprintf(interp->result+strlen(interp->result), "%s %d",
+	sprintf(res, "%s %d",
 		inet_ntoa(usock->client.sin_addr),
 		(int) ntohs(usock->client.sin_port));
+	Tcl_AppendResult(interp, res, NULL);
     }
 
     return TCL_OK;
@@ -512,7 +514,7 @@
 UdpBind(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     int mask = 0;
     Socket *usock;
@@ -570,7 +572,7 @@
 UdpMulticast(interp, argc, argv)
      Tcl_Interp *interp;
      int argc;
-     char **argv;
+     const char **argv;
 {
     Socket* usock;
     struct ip_mreq mreq;
@@ -578,6 +580,7 @@
     int tmp, optlen, sock, isNew, code;
     unsigned char ttl;
     Tcl_HashEntry *entryPtr;
+    char res[20];
     
     if (argc < 3) {
         Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
@@ -622,7 +625,8 @@
 	    return TCL_ERROR;
 	}
 	tmp = ttl;
-	sprintf(interp->result, "%d", tmp);
+	sprintf(res, "%d", tmp);
+	Tcl_SetResult(interp, res, TCL_VOLATILE);
 	return TCL_OK;
 
     } else if (strcmp(argv[2], "open") == 0) {
@@ -643,7 +647,7 @@
 	}
 
 	mreq.imr_multiaddr.s_addr = name.sin_addr.s_addr;
-	name.imr_interface.s_addr = htonl(INADDR_ANY);
+	mreq.imr_interface.s_addr = htonl(INADDR_ANY);
 
 	sock = TnmSocket(PF_INET, SOCK_DGRAM, 0);
 	if (sock == TNM_SOCKET_ERROR) {
@@ -732,7 +736,7 @@
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     char c;
 
