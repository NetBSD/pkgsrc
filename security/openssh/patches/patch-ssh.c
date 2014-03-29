$NetBSD: patch-ssh.c,v 1.3 2014/03/29 09:38:11 taca Exp $

Interix support

--- ssh.c.orig	2014-02-26 23:17:13.000000000 +0000
+++ ssh.c
@@ -943,7 +943,7 @@ main(int ac, char **av)
 	    strcmp(options.proxy_command, "-") == 0 &&
 	    options.proxy_use_fdpass)
 		fatal("ProxyCommand=- and ProxyUseFDPass are incompatible");
-#ifndef HAVE_CYGWIN
+#if defined(HAVE_CYGWIN) || defined(HAVE_INTERIX)
 	if (original_effective_uid != 0)
 		options.use_privileged_port = 0;
 #endif
