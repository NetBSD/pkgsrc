$NetBSD: patch-libntp_socktoa.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- libntp/socktoa.c.orig	2011-11-03 10:46:37.000000000 +0000
+++ libntp/socktoa.c
@@ -91,8 +91,8 @@ sockporttoa(
 	LIB_GETBUF(buf);
 	snprintf(buf, LIB_BUFLENGTH,
 		 (IS_IPV6(sock))
-		     ? "[%s]:%hu"
-		     : "%s:%hu",
+		     ? "[%s]:%u"
+		     : "%s:%u",
 		 atext, SRCPORT(sock));
 	errno = saved_errno;
 
