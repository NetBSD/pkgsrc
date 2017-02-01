$NetBSD: patch-tnm_snmp_tnmSnmpNet.c,v 1.2 2017/02/01 09:29:18 he Exp $

Constify.
Avoid use of interp->result.
Add code to try to re-sync trap message stream if we get too
large trap messages, but don't try more than 10 consecutive
attempts and instead abandon trap connection in that case.

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
 
@@ -843,6 +843,8 @@ TrapRecv(interp, packet, packetlen, from
 #else
     int len, rlen;
     char c;
+    static int resync;
+#define RESYNC_MAX 10
 
     /*
      * Read the message from the straps daemon. We expect the 
@@ -868,6 +870,71 @@ TrapRecv(interp, packet, packetlen, from
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
@@ -879,6 +946,8 @@ TrapRecv(interp, packet, packetlen, from
         len--;
     }
 
+#endif
+
     *packetlen = rlen;
 
     if (hexdump) {
@@ -1060,7 +1129,7 @@ ResponseProc(clientData, mask)
 	Tcl_BackgroundError(interp);
     }
     if (code == TCL_CONTINUE && hexdump) {
-	TnmWriteMessage(interp, interp->result);
+        TnmWriteMessage(interp, Tcl_GetStringResult(interp));
 	TnmWriteMessage(interp, "\n");
     }
 }
@@ -1102,7 +1171,7 @@ TrapProc(clientData, mask)
 	Tcl_BackgroundError(interp);
     }
     if (code == TCL_CONTINUE && hexdump) {
-	TnmWriteMessage(interp, interp->result);
+	TnmWriteMessage(interp, Tcl_GetStringResult(interp));
 	TnmWriteMessage(interp, "\n");
     }
 }
@@ -1147,7 +1216,7 @@ AgentProc(clientData, mask)
 	Tcl_BackgroundError(interp);
     }
     if (code == TCL_CONTINUE && hexdump) {
-	TnmWriteMessage(interp, interp->result);
+	TnmWriteMessage(interp, Tcl_GetStringResult(interp));
 	TnmWriteMessage(interp, "\n");
     }
 }
