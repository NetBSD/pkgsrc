$NetBSD: patch-unproto_unproto.c,v 1.1 2025/12/17 10:55:54 prlw1 Exp $

Fix build: implicit declaration of function 'strcmp'

--- unproto/unproto.c.orig	2014-03-14 04:33:19.000000000 +0000
+++ unproto/unproto.c
@@ -138,6 +138,7 @@ static char unproto_sccsid[] = "@(#) unp
 #include <sys/stat.h>
 #include <stdio.h>
 #include <errno.h>
+#include <string.h>
 
 extern void exit();
 extern int optind;
