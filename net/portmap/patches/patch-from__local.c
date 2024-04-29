$NetBSD: patch-from__local.c,v 1.1 2024/04/29 10:11:14 nia Exp $

Eliminate implicit function decls.

--- from_local.c.orig	1996-05-31 13:52:58.000000000 +0000
+++ from_local.c
@@ -46,6 +46,9 @@ static char sccsid[] = "@(#) from_local.
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
 #include <netdb.h>
 #include <netinet/in.h>
 #include <net/if.h>
