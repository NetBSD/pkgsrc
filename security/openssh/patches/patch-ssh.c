$NetBSD: patch-ssh.c,v 1.1 2013/05/01 19:58:26 imil Exp $

Interix support

--- ssh.c.orig	2012-07-06 03:45:01.000000000 +0000
+++ ssh.c
@@ -794,7 +794,7 @@ main(int ac, char **av)
 	if (ssh_connect(host, &hostaddr, options.port,
 	    options.address_family, options.connection_attempts, &timeout_ms,
 	    options.tcp_keep_alive, 
-#ifdef HAVE_CYGWIN
+#if defined(HAVE_CYGWIN) || defined(HAVE_INTERIX)
 	    options.use_privileged_port,
 #else
 	    original_effective_uid == 0 && options.use_privileged_port,
