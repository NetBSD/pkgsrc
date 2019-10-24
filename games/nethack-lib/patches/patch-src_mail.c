$NetBSD: patch-src_mail.c,v 1.1 2019/10/24 11:51:23 pho Exp $

Fix for NetBSD.

--- src/mail.c.orig	2019-05-08 07:00:15.000000000 +0000
+++ src/mail.c
@@ -71,7 +71,7 @@ static long laststattime;
 #if !defined(MAILPATH) && (defined(LINUX) || defined(__osf__))
 #define MAILPATH "/var/spool/mail/"
 #endif
-#if !defined(MAILPATH) && defined(__FreeBSD__)
+#if !defined(MAILPATH) && (defined(__FreeBSD__) || defined(__NetBSD__))
 #define MAILPATH "/var/mail/"
 #endif
 #if !defined(MAILPATH) && (defined(BSD) || defined(ULTRIX))
