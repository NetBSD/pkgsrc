$NetBSD: patch-src_low-level_smtp_mailsmtp.c,v 1.1 2015/04/27 13:34:05 jperkin Exp $

SunOS does not have sa_len.

--- src/low-level/smtp/mailsmtp.c.orig	2014-10-31 21:41:02.000000000 +0000
+++ src/low-level/smtp/mailsmtp.c
@@ -271,7 +271,7 @@ static int get_hostname(mailsmtp * sessi
     if (r != 0)
       return MAILSMTP_ERROR_HOSTNAME;
 
-#if (defined __linux__ || defined WIN32)
+#if (defined __linux__ || defined WIN32 || defined(__sun))
     r = getnameinfo(&addr, sizeof(addr), hostname, HOSTNAME_SIZE, NULL, 0, NI_NUMERICHOST);
 #else
     r = getnameinfo(&addr, addr.sa_len, hostname, HOSTNAME_SIZE, NULL, 0, NI_NUMERICHOST);
