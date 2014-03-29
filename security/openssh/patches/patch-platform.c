$NetBSD: patch-platform.c,v 1.3 2014/03/29 09:38:11 taca Exp $

Interix support

--- platform.c.orig	2014-01-21 01:59:29.000000000 +0000
+++ platform.c
@@ -89,7 +89,9 @@ platform_privileged_uidswap(void)
 	/* uid 0 is not special on Cygwin so always try */
 	return 1;
 #else
+#if !defined(HAVE_INTERIX)
 	return (getuid() == 0 || geteuid() == 0);
+#endif /* !HAVE_INTERIX */
 #endif
 }
 
