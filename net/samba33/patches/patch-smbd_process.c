$NetBSD: patch-smbd_process.c,v 1.1 2012/03/13 13:22:24 taca Exp $

* Fix for CVE-2012-0870.

--- smbd/process.c.orig	2011-07-24 19:09:38.000000000 +0000
+++ smbd/process.c
@@ -1656,7 +1656,7 @@ void chain_reply(struct smb_request *req
 	int size = smb_len(req->inbuf)+4;
 
 	int smb_com1, smb_com2 = CVAL(inbuf,smb_vwv0);
-	unsigned smb_off2 = SVAL(inbuf,smb_vwv1);
+	static unsigned smb_off2;
 	char *inbuf2;
 	int outsize2;
 	int new_size;
@@ -1681,8 +1681,16 @@ void chain_reply(struct smb_request *req
 		/* this is the first part of the chain */
 		orig_inbuf = inbuf;
 		orig_size = size;
+		smb_off2 = 0;
 	}
 
+	if (SVAL(inbuf,smb_vwv1) <= smb_off2) {
+		DEBUG(1, ("AndX offset not increasing\n"));
+		SCVAL(outbuf, smb_vwv0, 0xFF);
+		return;
+	}
+	smb_off2 = SVAL(inbuf, smb_vwv1);
+
 	/* Validate smb_off2 */
 	if ((smb_off2 < smb_wct - 4) || orig_size < (smb_off2 + 4 - smb_wct)) {
 		exit_server_cleanly("Bad chained packet");
