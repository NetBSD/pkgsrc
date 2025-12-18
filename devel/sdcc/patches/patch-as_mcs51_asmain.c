$NetBSD: patch-as_mcs51_asmain.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- as/mcs51/asmain.c.orig	2025-12-18 06:30:30.802341279 +0000
+++ as/mcs51/asmain.c
@@ -213,8 +213,7 @@ int fatalErrors=0;
 char relFile[128];
 
 int
-main(argc, argv)
-char *argv[];
+main(int argc, char *argv[])
 {
         register char *p;
         register int c, i;
