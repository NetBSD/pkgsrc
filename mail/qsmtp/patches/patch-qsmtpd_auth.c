$NetBSD: patch-qsmtpd_auth.c,v 1.1 2020/01/12 23:03:28 joerg Exp $

Use explicit_memset as explicit_bzero implementation on NetBSD.

--- qsmtpd/auth.c.orig	2020-01-11 21:10:23.629847795 +0000
+++ qsmtpd/auth.c
@@ -26,7 +26,9 @@
 #include <syslog.h>
 #include <time.h>
 #include <unistd.h>
-#ifdef NEED_BSD_STRING_H
+#ifdef HAS_EXP_MEMSET
+#define explicit_bzero(a, b) explicit_memset((a), 0, (b))
+#elif defined(NEED_BSD_STRING_H)
 #include <bsd/string.h>
 #elif defined(INSECURE_BZERO)
 // insecure fallback, could be optimized out by the compiler so memory is not overwritten
