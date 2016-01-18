$NetBSD: patch-ssh.c,v 1.5 2016/01/18 12:53:26 jperkin Exp $

Interix support
Disable roaming

--- ssh.c.orig	2015-08-21 04:49:03.000000000 +0000
+++ ssh.c
@@ -1084,7 +1084,7 @@ main(int ac, char **av)
 		    "disabling");
 		options.update_hostkeys = 0;
 	}
-#ifndef HAVE_CYGWIN
+#if defined(HAVE_CYGWIN) || defined(HAVE_INTERIX)
 	if (original_effective_uid != 0)
 		options.use_privileged_port = 0;
 #endif
@@ -1932,9 +1932,6 @@ ssh_session2(void)
 			fork_postauth();
 	}
 
-	if (options.use_roaming)
-		request_roaming();
-
 	return client_loop(tty_flag, tty_flag ?
 	    options.escape_char : SSH_ESCAPECHAR_NONE, id);
 }
