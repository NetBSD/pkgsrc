$NetBSD: patch-ssh.c,v 1.2 2013/12/01 06:11:41 taca Exp $

Interix support

--- ssh.c.orig	2013-07-25 01:55:53.000000000 +0000
+++ ssh.c
@@ -820,7 +820,7 @@ main(int ac, char **av)
 	if (ssh_connect(host, &hostaddr, options.port,
 	    options.address_family, options.connection_attempts, &timeout_ms,
 	    options.tcp_keep_alive, 
-#ifdef HAVE_CYGWIN
+#if defined(HAVE_CYGWIN) || defined(HAVE_INTERIX)
 	    options.use_privileged_port,
 #else
 	    original_effective_uid == 0 && options.use_privileged_port,
