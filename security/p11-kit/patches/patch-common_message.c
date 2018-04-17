$NetBSD: patch-common_message.c,v 1.1 2018/04/17 13:26:15 wiz Exp $

NetBSD does not have uselocale()
https://github.com/p11-glue/p11-kit/issues/143

--- common/message.c.orig	2018-01-31 12:47:38.000000000 +0000
+++ common/message.c
@@ -118,7 +118,7 @@ p11_message_err (int errnum,
 	buffer[length] = 0;
 
 	snprintf (strerr, sizeof (strerr), "Unknown error %d", errnum);
-#ifdef HAVE_STRERROR_L
+#if defined(HAVE_STRERROR_L) && !defined(__NetBSD__)
 	loc = uselocale ((locale_t) 0);
 	if (loc != NULL)
 		strncpy (strerr, strerror_l (errnum, loc), sizeof (strerr));
