$NetBSD: patch-platform.c,v 1.5 2016/01/18 12:53:26 jperkin Exp $

Interix support

--- platform.c.orig	2015-08-21 04:49:03.000000000 +0000
+++ platform.c
@@ -90,7 +90,9 @@ platform_privileged_uidswap(void)
 	/* uid 0 is not special on Cygwin so always try */
 	return 1;
 #else
+#if !defined(HAVE_INTERIX)
 	return (getuid() == 0 || geteuid() == 0);
+#endif /* !HAVE_INTERIX */
 #endif
 }
 
