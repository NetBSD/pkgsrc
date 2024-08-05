$NetBSD: patch-rfc931.c,v 1.1 2024/08/05 12:48:18 tnn Exp $

--- rfc931.c.orig	2024-08-05 13:51:18.248160163 +0000
+++ rfc931.c
@@ -23,6 +23,7 @@ static char sccsid[] = "@(#) rfc931.c 1.
 #include <setjmp.h>
 #include <signal.h>
 #include <string.h>
+#include <unistd.h>
 
 /* Local stuff. */
 
