$NetBSD: patch-thermoms.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- thermoms.c.orig	2013-01-11 01:31:32.000000000 +0000
+++ thermoms.c
@@ -68,7 +68,7 @@ int InputMissionType(ThermoStateType *,i
 //----------------------------------------------------------------------
 //  This is the Main routine for thermoms.
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    int Fahrenheit=FALSE,num,i,j;
    char str[800];
