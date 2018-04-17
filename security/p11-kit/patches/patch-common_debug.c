$NetBSD: patch-common_debug.c,v 1.1 2018/04/17 13:26:15 wiz Exp $

NetBSD does not have uselocale()
https://github.com/p11-glue/p11-kit/issues/143

--- common/debug.c.orig	2018-01-31 12:47:38.000000000 +0000
+++ common/debug.c
@@ -162,7 +162,7 @@ p11_debug_message_err (int flag,
 		va_end (args);
 
 		snprintf (strerr, sizeof (strerr), "Unknown error %d", errnum);
-#ifdef HAVE_STRERROR_L
+#if defined(HAVE_STRERROR_L) && !defined(__NetBSD__)
 		loc = uselocale ((locale_t) 0);
 		if (loc != NULL)
 			strncpy (strerr, strerror_l (errnum, loc), sizeof (strerr));
