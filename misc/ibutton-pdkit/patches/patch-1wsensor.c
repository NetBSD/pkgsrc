$NetBSD: patch-1wsensor.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- 1wsensor.c.orig	2013-01-11 01:30:59.000000000 +0000
+++ 1wsensor.c
@@ -63,7 +63,7 @@ FILE *fp;
 //----------------------------------------------------------------------
 //  This is the Main routine for 1wsensor 
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    int ShowStatus=FALSE,filenum,first,rslt;
    uchar tagdata[MSGMAX];
