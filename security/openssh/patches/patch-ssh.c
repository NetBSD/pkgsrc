$NetBSD: patch-ssh.c,v 1.4 2015/07/09 16:14:23 taca Exp $

Interix support

--- ssh.c.orig	2015-07-01 02:35:31.000000000 +0000
+++ ssh.c
@@ -1083,7 +1083,7 @@ main(int ac, char **av)
 		    "disabling");
 		options.update_hostkeys = 0;
 	}
-#ifndef HAVE_CYGWIN
+#if defined(HAVE_CYGWIN) || defined(HAVE_INTERIX)
 	if (original_effective_uid != 0)
 		options.use_privileged_port = 0;
 #endif
