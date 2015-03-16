$NetBSD: patch-redir.c,v 1.2 2015/03/16 19:19:58 tron Exp $

Decode SOL_CONTROLS_FROM_HOST messages. This fixes compatiblity problems
with the AMT interface of an Lenovo ThinkServer TS140.

Patch taken from GIT repository:

https://www.kraxel.org/cgit/amtterm/patch/?id=0ece5135fef56dbd0d94957c334655a57adb7212

--- redir.c.orig	2011-05-26 10:19:45.000000000 +0100
+++ redir.c	2015-03-16 19:16:49.000000000 +0000
@@ -281,8 +281,11 @@
 
 	switch (count) {
 	case -1:
-	    snprintf(r->err, sizeof(r->err), "read(socket): %s", strerror(errno));
-	    return -1;
+	    if (errno != EAGAIN) {
+	      snprintf(r->err, sizeof(r->err), "read(socket): %s", strerror(errno));
+	      return -1;
+	    }
+	    break;
 	case 0:
 	    snprintf(r->err, sizeof(r->err), "EOF from socket");
 	    return -1;
@@ -298,6 +301,9 @@
     return bshift;
 }
 
+static int in_loopback_mode = 0;
+static int powered_off = 0;
+
 int redir_data(struct redir *r)
 {
     int rc, bshift;
@@ -382,6 +388,55 @@
 		goto again;
 	    redir_stop(r);
 	    break;
+	case SOL_CONTROLS_FROM_HOST: {
+	  bshift = r->blen; /* FIXME */
+	  if (r->blen < bshift)
+	    goto again;
+	  
+	  /* Host sends this message to the Management Console when
+	   * the host has changed its COM port control lines. This
+	   * message is likely to be one of the first messages that
+	   * the Host sends to the Console after it starts SOL
+	   * redirection.
+	   */
+	  struct controls_from_host_message *msg = (struct controls_from_host_message *) r->buf;
+	  //printf("Type %x, control %d, status %d\n", msg->type, msg->control, msg->status);
+	  if (msg->status & LOOPBACK_ACTIVE) {
+	    if (r->verbose)
+	      fprintf (stderr, "Warning, SOL device is running in loopback mode.  Text input may not be accepted\n");
+	    in_loopback_mode = 1;
+	  } else if (in_loopback_mode) {
+	    if (r->verbose)
+	      fprintf (stderr, "SOL device is no longer running in loopback mode\n");
+	    in_loopback_mode = 0;
+	  }
+
+	  if (0 == (msg->status & SYSTEM_POWER_STATE))  {
+	    if (r->verbose)
+	      fprintf (stderr, "The system is powered off.\n");
+	    powered_off = 1;
+	  } else if (powered_off) {
+	    if (r->verbose)
+	      fprintf (stderr, "The system is powered on.\n");
+	    powered_off = 0;
+	  }
+	  
+	  if (r->verbose) {
+	    if (msg->status & (TX_OVERFLOW|RX_FLUSH_TIMEOUT|TESTMODE_ACTIVE))
+	      fprintf (stderr, "Other unhandled status condition\n");
+	    
+	    if (msg->control & RTS_CONTROL) 
+	      fprintf (stderr, "RTS is asserted on the COM Port\n");
+	    
+	    if (msg->control & DTR_CONTROL) 
+	      fprintf (stderr, "DTR is asserted on the COM Port\n");
+	    
+	    if (msg->control & BREAK_CONTROL) 
+	      fprintf (stderr, "BREAK is asserted on the COM Port\n");
+	  }
+
+	  break;
+	}
 	default:
 	    snprintf(r->err, sizeof(r->err), "%s: unknown r->buf 0x%02x",
 		     __FUNCTION__, r->buf[0]);
