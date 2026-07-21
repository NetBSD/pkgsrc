$NetBSD: patch-smbd_password.c,v 1.1 2026/07/21 21:17:40 rjs Exp $

Arguments to getnetgrent(3) need to be const.

--- smbd/password.c.orig	2026-07-21 17:35:29.458495371 +0000
+++ smbd/password.c
@@ -487,7 +487,7 @@ static char *validate_group(struct smbd_server_connect
 {
 #ifdef HAVE_NETGROUP
 	{
-		char *host, *user, *domain;
+		const char *host, *user, *domain;
 		struct auth_context *actx = sconn->smb1.negprot.auth_context;
 		bool enc = sconn->smb1.negprot.encrypted_passwords;
 		setnetgrent(group);
