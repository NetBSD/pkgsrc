$NetBSD: patch-openbsd-compat_bsd-openpty.c,v 1.4 2016/12/30 04:43:16 taca Exp $

Interix support

--- openbsd-compat/bsd-openpty.c.orig	2016-12-19 04:59:41.000000000 +0000
+++ openbsd-compat/bsd-openpty.c
@@ -121,6 +121,7 @@ openpty(int *amaster, int *aslave, char 
 		return (-1);
 	}
 
+#if !defined(HAVE_INTERIX)
 	/*
 	 * Try to push the appropriate streams modules, as described
 	 * in Solaris pts(7).
@@ -130,6 +131,7 @@ openpty(int *amaster, int *aslave, char 
 # ifndef __hpux
 	ioctl(*aslave, I_PUSH, "ttcompat");
 # endif /* __hpux */
+#endif /* !HAVE_INTERIX */
 
 	return (0);
 
