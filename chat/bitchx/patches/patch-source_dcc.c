$NetBSD: patch-source_dcc.c,v 1.1 2024/03/16 13:11:55 nia Exp $

Fixes a security issue with DCC.
https://sourceforge.net/p/bitchx/git/ci/726884b0b076d0a77f7f5c7866caa09a164e8ae9/

--- source/dcc.c.orig	2014-03-02 19:59:13.000000000 +0000
+++ source/dcc.c
@@ -1420,6 +1420,7 @@ UserList *ul = NULL;
 			if (autoresume && stat(fullname, &sb) != -1) {
 				n->transfer_orders.byteoffset = sb.st_size;
 				n->bytes_read = 0L;
+				new_d->sock.flags |= DCC_RESUME_REQ;
 				send_ctcp(CTCP_PRIVMSG, nick, CTCP_DCC, "RESUME %s %d %ld", n->filename, ntohs(n->remport), sb.st_size);
 			} else {
 				DCC_int *new = NULL;
@@ -3437,6 +3438,7 @@ void dcc_getfile_resume_start (char *nic
 {
 SocketList *s;
 DCC_int *n;
+const DCC_List *pending;
 char *tmp = NULL;
 char *fullname = NULL;
 struct stat sb;
@@ -3449,6 +3451,14 @@ struct stat sb;
 		put_it("%s", convert_output_format("$G %RDCC%n warning in dcc_getfile_resume_start", NULL));
 		return;
 	}
+	
+	pending = find_dcc_pending(nick, description, NULL, DCC_FILEREAD, 0, -1);
+	if (!pending || !(pending->sock.flags & DCC_RESUME_REQ))
+	{
+		put_it("%s", convert_output_format("$G %RDCC%n Ignoring unsolicited ACCEPT from $0", "%s", nick));
+		return;
+	}
+
 	if (!(n = dcc_create(nick, description, NULL, 0, port?atol(port):0, DCC_FILEREAD, DCC_TWOCLIENTS|DCC_OFFER, start_dcc_get)))
 		return;
 
@@ -3495,17 +3505,13 @@ int		blocksize = 0;
 	user = get_dcc_args(&args, &passwd, &port, &blocksize);
 	if (!user)
 	{
-		put_it("%s", convert_output_format("$G %RDCC%n You must supply a nickname for DCC get", NULL, NULL));
+		put_it("%s", convert_output_format("$G %RDCC%n You must supply a nickname for DCC RESUME", NULL));
 		return;
 	}
+
 	if (!blocksize || blocksize > MAX_DCC_BLOCK_SIZE)
 		blocksize = get_int_var(DCC_BLOCK_SIZE_VAR);
 
-	if (!user)
-	{
-		put_it("%s", convert_output_format("$G %RDCC%n You must supply a nickname for DCC RESUME", NULL));
-		return;
-	}
 	if (args && *args)
 		filename = args;
 
@@ -3564,6 +3570,8 @@ int		blocksize = 0;
 		n->blocksize = blocksize;
 		n->transfer_orders.byteoffset = sb.st_size;
 
+		s->flags |= DCC_RESUME_REQ;
+
 		old_dp = doing_privmsg;	old_dn = doing_notice; old_dc = in_ctcp_flag;
 		/* Just in case we have to fool the protocol enforcement. */
 		doing_privmsg = doing_notice = in_ctcp_flag = 0;
