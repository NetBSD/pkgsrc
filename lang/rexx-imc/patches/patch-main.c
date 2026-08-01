$NetBSD: patch-main.c,v 1.1 2026/08/01 18:11:29 ryoon Exp $

--- main.c.orig	2026-08-01 17:49:54.934209644 +0000
+++ main.c
@@ -23,6 +23,7 @@ static RXSTRING answer;
 static RXSTRING instore[2];    /* "instore" argument for RexxStart */
 static RXSTRING answer;
 
+int
 main(argc,argv)  /* This function gives an interface between the command */
 int argc;        /* line and the API function RexxStart(). */
 char *argv[];
