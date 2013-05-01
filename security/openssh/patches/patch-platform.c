$NetBSD: patch-platform.c,v 1.2 2013/05/01 19:58:26 imil Exp $

Interix support

--- platform.c.orig	2013-03-12 00:31:05.000000000 +0000
+++ platform.c
@@ -81,7 +81,9 @@ platform_privileged_uidswap(void)
 	/* uid 0 is not special on Cygwin so always try */
 	return 1;
 #else
+#if !defined(HAVE_INTERIX)
 	return (getuid() == 0 || geteuid() == 0);
+#endif /* !HAVE_INTERIX */
 #endif
 }
 
