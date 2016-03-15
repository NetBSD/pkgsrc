$NetBSD: patch-ssh.c,v 1.6 2016/03/15 20:54:07 bsiegert Exp $

Interix support

--- ssh.c.orig	2016-03-09 18:04:48.000000000 +0000
+++ ssh.c
@@ -1097,7 +1097,7 @@ main(int ac, char **av)
 	}
 	if (options.connection_attempts <= 0)
 		fatal("Invalid number of ConnectionAttempts");
-#ifndef HAVE_CYGWIN
+#if !defined(HAVE_CYGWIN) && !defined(HAVE_INTERIX)
 	if (original_effective_uid != 0)
 		options.use_privileged_port = 0;
 #endif
