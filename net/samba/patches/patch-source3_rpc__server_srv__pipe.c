$NetBSD: patch-source3_rpc__server_srv__pipe.c,v 1.1 2017/05/24 15:36:42 he Exp $

Adapt & apply fix for
https://bugzilla.samba.org/show_bug.cgi?id=12780 (non-public)
from
https://www.samba.org/samba/ftp/patches/security/samba-4.6.3-4.5.9-4.4.13-CVE-2017-7494.patch
Should fix CVE-2017-7494.

--- ../source3/rpc_server/srv_pipe.c.orig	2015-02-22 14:11:32.000000000 +0000
+++ ../source3/rpc_server/srv_pipe.c
@@ -376,6 +376,11 @@ bool is_known_pipename(const char *cli_f
 	const char *pipename = cli_filename;
 	NTSTATUS status;
 
+	if (strchr(pipename, '/')) {
+		DEBUG(1, ("Refusing open on pipe %s\n", pipename));
+		return false;
+	}
+
 	if (strnequal(pipename, "\\PIPE\\", 6)) {
 		pipename += 5;
 	}
