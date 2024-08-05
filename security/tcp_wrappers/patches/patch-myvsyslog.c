$NetBSD: patch-myvsyslog.c,v 1.1 2024/08/05 12:48:18 tnn Exp $

--- myvsyslog.c.orig	2024-08-05 14:02:49.411601058 +0000
+++ myvsyslog.c
@@ -14,10 +14,12 @@ static char sccsid[] = "@(#) myvsyslog.c
 #ifdef vsyslog
 
 #include <stdio.h>
+#include <syslog.h>
 
 #include "tcpd.h"
 #include "mystdarg.h"
 
+void
 myvsyslog(severity, format, ap)
 int     severity;
 char   *format;
