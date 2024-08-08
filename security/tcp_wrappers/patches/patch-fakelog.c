$NetBSD: patch-fakelog.c,v 1.2 2024/08/08 20:34:11 triaxx Exp $

Add missing specifier to avoid implicit int return.

--- fakelog.c.orig	1994-12-28 16:42:22.000000000 +0000
+++ fakelog.c
@@ -17,6 +17,7 @@ static char sccsid[] = "@(#) fakelog.c 1
 
 /* ARGSUSED */
 
+void
 openlog(name, logopt, facility)
 char   *name;
 int     logopt;
@@ -27,6 +28,7 @@ int     facility;
 
 /* vsyslog - format one record */
 
+void
 vsyslog(severity, fmt, ap)
 int     severity;
 char   *fmt;
@@ -43,6 +45,7 @@ va_list ap;
 
 /* VARARGS */
 
+void
 VARARGS(syslog, int, severity)
 {
     va_list ap;
@@ -56,6 +59,7 @@ VARARGS(syslog, int, severity)
 
 /* closelog - dummy */
 
+void
 closelog()
 {
     /* void */
