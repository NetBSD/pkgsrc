$NetBSD: patch-as_hc08_asmain.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- as/hc08/asmain.c.orig	2025-12-18 06:05:53.579394656 +0000
+++ as/hc08/asmain.c
@@ -151,8 +151,7 @@ int fatalErrors=0;
 char relFile[128];
 
 int
-main(argc, argv)
-char *argv[];
+main(int argc, char *argv[])
 {
         register char *p;
         register int c, i;
