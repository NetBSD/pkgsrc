$NetBSD: patch-tnm_snmp_tnmSnmpNet.c,v 1.3 2018/05/14 08:57:57 he Exp $

Constify.
Avoid use of interp->result.
Add code to try to re-sync trap message stream if we get too
large trap messages, but don't try more than 10 consecutive
attempts and instead abandon trap connection in that case.
Provide more diagnostics leading up to abandoning an straps
connection.  When abandoning a trap connection, check if an straps
child's status should be collected.

--- tnm/snmp/tnmSnmpNet.c.orig	1997-08-26 18:55:45.000000000 +0000
+++ tnm/snmp/tnmSnmpNet.c
@@ -13,6 +13,7 @@
  */
 
 #include "tnmSnmp.h"
+#include <sys/wait.h>
 
 #ifndef __WIN32__
 #include <sys/un.h>
@@ -140,8 +141,10 @@ xread(fd, buf, len)
 {
     int rc;
     
+    errno = 0;
     while ((rc = read(fd, buf, len)) < 0 
 	   && (errno == EINTR || errno == EAGAIN)) {
+	errno = 0;
 	continue;
     }
     
@@ -170,7 +173,7 @@ straps(interp)
     Tcl_Interp *interp;
 {
     int *pidArray, argc = 1;
-    static char *argv[2] = { NULL, 0 };
+    static const char *argv[2] = { NULL, 0 };
     static Tcl_Channel channel = NULL;
     static char *straps = NULL;
 
@@ -841,8 +844,10 @@ TrapRecv(interp, packet, packetlen, from
 
     return TCL_OK;
 #else
-    int len, rlen;
+    int len, rlen, res, pid;
     char c;
+    static int resync;
+#define RESYNC_MAX 10
 
     /*
      * Read the message from the straps daemon. We expect the 
@@ -854,31 +859,112 @@ TrapRecv(interp, packet, packetlen, from
      * n byte - trap message.
      */
 
-    if (xread(trap_sock, (char *) &from->sin_addr.s_addr, 4) != 4) {
+    if ((res = xread(trap_sock, (char *) &from->sin_addr.s_addr, 4)) != 4) {
+	if (res < 0)
+	    fprintf(stderr, "TrapRecv: error: %s\n", strerror(errno));
+	fprintf(stderr, "TrapRecv: could not read addr: %d\n", res);
 	goto errorExit;
     }
-    if (xread(trap_sock, (char *) &from->sin_port, 2) != 2) {
+    if ((res = xread(trap_sock, (char *) &from->sin_port, 2)) != 2) {
+	if (res < 0)
+	    fprintf(stderr, "TrapRecv: error: %s\n", strerror(errno));
+	fprintf(stderr, "TrapRecv: could not read port: %d\n", res);
 	goto errorExit;
     }
-    if (xread(trap_sock, (char *) &len, 4) != 4) {
+    if ((res = xread(trap_sock, (char *) &len, 4)) != 4) {
+	if (res < 0)
+	    fprintf(stderr, "TrapRecv: error: %s\n", strerror(errno));
+	fprintf(stderr, "TrapRecf: could not read length: %d\n", res);
 	goto errorExit;
     }
     rlen = len < *packetlen ? len : *packetlen;
-    if (xread(trap_sock, (char *) packet, rlen) <= 0) {
+    if ((res = xread(trap_sock, (char *) packet, rlen)) <= 0) {
+	fprintf(stderr, "TrapRecv: error: %s\n", strerror(errno));
+	fprintf(stderr, "TrapRecv: could not read packet: %d\n", res);
 	goto errorExit;
     }
 
+#if 1
+    /*
+     * preposterous length?
+     * Do repeated read()s until EAGAIN,
+     * and then say we're done re-syncing trap stream.
+     */
+
+    if (len > *packetlen) {
+	char buf[2048];
+	int l, rem;
+	Tcl_DString dst;
+
+	Tcl_DStringInit(&dst);
+
+	DumpPacket(interp, packet, *packetlen, "TrapRecv huge packet", from);
+
+	Tcl_DStringAppend(&dst, "TrapRecv: preposterous packet length: ", -1);
+	sprintf(buf, "%d\n", len);
+	Tcl_DStringAppend(&dst, buf, -1);
+
+    again:
+	while((l = read(trap_sock, buf, sizeof(buf))) > 0) {
+	  sprintf(buf, "Skipping %d bytes\n", l);
+	  Tcl_DStringAppend(&dst, buf, -1);
+	}
+	if (errno == EAGAIN) {
+	  Tcl_DStringAppend(&dst, "Hit EAGAIN, attempting re-sync\n", -1);
+	} else if (errno == EINTR) {
+	  Tcl_DStringAppend(&dst, "Hit EINTR, skipping more\n", -1);
+	  goto again;
+	} else if (l < 0) {
+	  Tcl_DStringAppend(&dst, "Hit other error: ", -1);
+	  Tcl_DStringAppend(&dst, strerror(errno), -1);
+	  Tcl_DStringAppend(&dst, "\nAborting trap connection.\n", -1);
+	  TnmWriteMessage(interp, Tcl_DStringValue(&dst));
+	  Tcl_DStringFree(&dst);
+	  goto errorExit;
+	}
+	resync++;
+
+	/* ...and send accumulated output */
+	TnmWriteMessage(interp, Tcl_DStringValue(&dst));
+	Tcl_DStringFree(&dst);
+
+	/*
+	 * Don't try too many consecutive re-sync attempts;
+	 * it indicates we're unable to re-sync.
+	 */
+	if (resync > RESYNC_MAX) {
+	    Tcl_DStringInit(&dst);
+	    
+	    Tcl_DStringAppend(&dst,
+			      "Too many consecutive resync attempts!\n", -1);
+	    Tcl_DStringAppend(&dst,
+			      "Aborting trap connection.\n", -1);
+	    TnmWriteMessage(interp, Tcl_DStringValue(&dst));
+	    Tcl_DStringFree(&dst);
+	    goto errorExit;
+	}
+    } else {
+	resync = 0;		/* read complete message, OK length */
+    }
+    
+#else
+
     /*
      * Eat up any remaining data-bytes.
      */
 
     while (len > *packetlen) {
-        if (xread(trap_sock, &c, 1) != 1) {
+        if ((res = xread(trap_sock, &c, 1)) != 1) {
+	    if (res < 0)
+		fprintf(stderr, "TrapRecv: could not read remaining bytes: %s\n", strerror(errno));
+	    fprintf(stderr, "TrapRecv: consume-rest read result: %d\n", res);
 	    goto errorExit;
 	}
         len--;
     }
 
+#endif
+
     *packetlen = rlen;
 
     if (hexdump) {
@@ -894,8 +980,15 @@ TrapRecv(interp, packet, packetlen, from
     return TCL_OK;
 
  errorExit:
+    fprintf(stderr, "TrapRecv: errorExit, closing trap receiver\n");
     Tnm_SnmpTrapClose();
     Tcl_SetResult(interp, "lost connection to straps daemon", TCL_STATIC);
+    pid = waitpid(-1, &res, WNOHANG); /* We may have started straps() */
+    if (pid > 0) {
+	fprintf(stderr, "TrapRecv: collected status for pid %d\n", pid);
+    } else if (pid == -1) {
+	fprintf(stderr, "TrapRecv: wait returned %s\n", strerror(pid));
+    }
     return TCL_ERROR;
 #endif
 }
@@ -1060,7 +1153,7 @@ ResponseProc(clientData, mask)
 	Tcl_BackgroundError(interp);
     }
     if (code == TCL_CONTINUE && hexdump) {
-	TnmWriteMessage(interp, interp->result);
+        TnmWriteMessage(interp, Tcl_GetStringResult(interp));
 	TnmWriteMessage(interp, "\n");
     }
 }
@@ -1102,7 +1195,7 @@ TrapProc(clientData, mask)
 	Tcl_BackgroundError(interp);
     }
     if (code == TCL_CONTINUE && hexdump) {
-	TnmWriteMessage(interp, interp->result);
+	TnmWriteMessage(interp, Tcl_GetStringResult(interp));
 	TnmWriteMessage(interp, "\n");
     }
 }
@@ -1147,7 +1240,7 @@ AgentProc(clientData, mask)
 	Tcl_BackgroundError(interp);
     }
     if (code == TCL_CONTINUE && hexdump) {
-	TnmWriteMessage(interp, interp->result);
+	TnmWriteMessage(interp, Tcl_GetStringResult(interp));
 	TnmWriteMessage(interp, "\n");
     }
 }
