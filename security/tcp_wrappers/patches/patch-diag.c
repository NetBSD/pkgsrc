$NetBSD: patch-diag.c,v 1.1 2024/08/05 12:48:18 tnn Exp $

--- diag.c.orig	2024-08-05 14:02:57.737811465 +0000
+++ diag.c
@@ -24,6 +24,10 @@ static char sccsid[] = "@(#) diag.c 1.1
 #include "tcpd.h"
 #include "mystdarg.h"
 
+#ifdef vsyslog
+void myvsyslog(int, char*, va_list);
+#endif
+
 struct tcpd_context tcpd_context;
 jmp_buf tcpd_buf;
 
