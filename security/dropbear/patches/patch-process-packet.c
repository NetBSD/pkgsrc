$NetBSD: patch-process-packet.c,v 1.1 2023/12/20 17:09:36 wiz Exp $

Terrapin fix
https://github.com/mkj/dropbear/commit/6e43be5c7b99dbee49dc72b6f989f29fdd7e9356

--- process-packet.c.orig	2022-11-14 14:30:00.000000000 +0000
+++ process-packet.c
@@ -44,6 +44,7 @@ void process_packet() {
 
 	unsigned char type;
 	unsigned int i;
+	unsigned int first_strict_kex = ses.kexstate.strict_kex && !ses.kexstate.donefirstkex;
 	time_t now;
 
 	TRACE2(("enter process_packet"))
@@ -54,22 +55,24 @@ void process_packet() {
 	now = monotonic_now();
 	ses.last_packet_time_keepalive_recv = now;
 
-	/* These packets we can receive at any time */
-	switch(type) {
 
-		case SSH_MSG_IGNORE:
-			goto out;
-		case SSH_MSG_DEBUG:
-			goto out;
+	if (type == SSH_MSG_DISCONNECT) {
+		/* Allowed at any time */
+		dropbear_close("Disconnect received");
+	}
 
-		case SSH_MSG_UNIMPLEMENTED:
-			/* debugging XXX */
-			TRACE(("SSH_MSG_UNIMPLEMENTED"))
-			goto out;
-			
-		case SSH_MSG_DISCONNECT:
-			/* TODO cleanup? */
-			dropbear_close("Disconnect received");
+	/* These packets may be received at any time,
+	   except during first kex with strict kex */
+	if (!first_strict_kex) {
+		switch(type) {
+			case SSH_MSG_IGNORE:
+				goto out;
+			case SSH_MSG_DEBUG:
+				goto out;
+			case SSH_MSG_UNIMPLEMENTED:
+				TRACE(("SSH_MSG_UNIMPLEMENTED"))
+				goto out;
+		}
 	}
 
 	/* Ignore these packet types so that keepalives don't interfere with
@@ -98,7 +101,8 @@ void process_packet() {
 			if (type >= 1 && type <= 49
 				&& type != SSH_MSG_SERVICE_REQUEST
 				&& type != SSH_MSG_SERVICE_ACCEPT
-				&& type != SSH_MSG_KEXINIT)
+				&& type != SSH_MSG_KEXINIT
+				&& !first_strict_kex)
 			{
 				TRACE(("unknown allowed packet during kexinit"))
 				recv_unimplemented();
