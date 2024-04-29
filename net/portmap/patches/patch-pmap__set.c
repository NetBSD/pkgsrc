$NetBSD: patch-pmap__set.c,v 1.1 2024/04/29 10:11:14 nia Exp $

Eliminate implicit function decls.

--- pmap_set.c.orig	2024-04-29 10:03:29.969754569 +0000
+++ pmap_set.c
@@ -10,6 +10,7 @@ static char sccsid[] = "@(#) pmap_set.c 
 #endif
 
 #include <stdio.h>
+#include <string.h>
 #include <sys/types.h>
 #ifdef SYSV40
 #include <netinet/in.h>
