$NetBSD: patch-thermodl.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- thermodl.c.orig	2013-01-11 01:31:30.000000000 +0000
+++ thermodl.c
@@ -65,7 +65,7 @@ void PrintResults(ThermoStateType *,FILE
 //----------------------------------------------------------------------
 //  This is the Main routine for thermodl.
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    int Fahrenheit=FALSE,filenum,num,i,j;
    FILE *fp;
