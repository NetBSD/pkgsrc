$NetBSD: patch-client_client.c,v 1.3.2.2 2012/02/05 18:41:14 spz Exp $

Restore compatibility with CIFS server on Apple Time Capsule. Patch
take from here:

https://bugzilla.samba.org/show_bug.cgi?id=8139

--- client/client.c.orig	2012-01-29 19:40:43.000000000 +0000
+++ client/client.c	2012-01-30 22:39:12.000000000 +0000
@@ -4844,12 +4844,16 @@
 		memset(garbage, 0xf0, sizeof(garbage));
 		status = cli_echo(cli, 1, data_blob_const(garbage, sizeof(garbage)));
 
-		if (!NT_STATUS_IS_OK(status)) {
+		if (NT_STATUS_EQUAL(status, NT_STATUS_PIPE_BROKEN) ||
+				NT_STATUS_EQUAL(status, NT_STATUS_END_OF_FILE) ||
+				NT_STATUS_EQUAL(status, NT_STATUS_IO_TIMEOUT)) {
 			DEBUG(0, ("SMBecho failed. Maybe server has closed "
 				"the connection\n"));
 			finished = true;
 			smb_readline_done();
 		}
+		/* Ignore all other errors - sometimes servers simply
+		   don't implement SMBecho (Apple for example). */
 	}
 }
 
