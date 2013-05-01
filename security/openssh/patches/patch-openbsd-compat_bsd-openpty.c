$NetBSD: patch-openbsd-compat_bsd-openpty.c,v 1.1 2013/05/01 19:58:26 imil Exp $

Interix support

--- openbsd-compat/bsd-openpty.c.orig	2006-08-24 09:52:30.000000000 +0000
+++ openbsd-compat/bsd-openpty.c
@@ -121,15 +121,17 @@ openpty(int *amaster, int *aslave, char 
 		return (-1);
 	}
 
+#if !defined(HAVE_INTERIX)
 	/*
 	 * Try to push the appropriate streams modules, as described 
 	 * in Solaris pts(7).
 	 */
 	ioctl(*aslave, I_PUSH, "ptem");
 	ioctl(*aslave, I_PUSH, "ldterm");
-# ifndef __hpux
+  # ifndef __hpux
 	ioctl(*aslave, I_PUSH, "ttcompat");
-# endif /* __hpux */
+  # endif /* __hpux */
+#endif /* !HAVE_INTERIX */
 
 	return (0);
 
