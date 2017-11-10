$NetBSD: patch-authenticate.c,v 1.3 2017/11/10 06:59:16 spz Exp $

3.1.2 is not vulnerable to CVE-2017-15994, the code is different,
but not allowing fallback to MD4 for passwords is a good idea by now.
Patch from
https://git.samba.org/?p=rsync.git;a=blobdiff;f=authenticate.c;h=a106b0f60a8cb88e37080bc5e2a58ce28c66f379;hp=d60ee20b6b53a9351efbdf175f36525ead220de6;hb=9a480deec4d20277d8e20bc55515ef0640ca1e55;hpb=c252546ceeb0925eb8a4061315e3ff0a8c55b48b

--- authenticate.c.orig	2015-08-24 18:54:00.000000000 +0000
+++ authenticate.c
@@ -22,6 +22,7 @@
 #include "itypes.h"
 
 extern int read_only;
+extern int protocol_version;
 extern char *password_file;
 
 /***************************************************************************
@@ -237,6 +238,11 @@ char *auth_server(int f_in, int f_out, i
 	if (!users || !*users)
 		return "";
 
+	if (protocol_version < 21) { /* Don't allow a weak checksum for the password. */
+		rprintf(FERROR, "ERROR: protocol version is too old!\n");
+		exit_cleanup(RERR_PROTOCOL);
+	}
+
 	gen_challenge(addr, challenge);
 
 	io_printf(f_out, "%s%s\n", leader, challenge);
