$NetBSD: patch-client_client.c,v 1.2 2012/01/30 15:48:11 tron Exp $

Restore compatibility with CIFS server on Apple Time Capsule:

https://bugzilla.samba.org/show_bug.cgi?id=8139

--- client/client.c.orig	2012-01-29 19:40:43.000000000 +0000
+++ client/client.c	2012-01-30 13:05:27.000000000 +0000
@@ -4844,7 +4844,8 @@
 		memset(garbage, 0xf0, sizeof(garbage));
 		status = cli_echo(cli, 1, data_blob_const(garbage, sizeof(garbage)));
 
-		if (!NT_STATUS_IS_OK(status)) {
+		if (!NT_STATUS_IS_OK(status)
+		    && NT_STATUS_V(status) != 0xffff0002) {
 			DEBUG(0, ("SMBecho failed. Maybe server has closed "
 				"the connection\n"));
 			finished = true;
