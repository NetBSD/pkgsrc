$NetBSD: patch-initcopr.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- initcopr.c.orig	2013-01-11 01:31:10.000000000 +0000
+++ initcopr.c
@@ -56,7 +56,7 @@ FILE *fp;
 //----------------------------------------------------------------------
 //  This is the Main routine for initcopr 
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    int ShowStatus=FALSE,filenum;
    char msg[200];
