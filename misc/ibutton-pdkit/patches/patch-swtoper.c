$NetBSD: patch-swtoper.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- swtoper.c.orig	2013-01-11 01:34:38.000000000 +0000
+++ swtoper.c
@@ -54,7 +54,7 @@ extern int getkeystroke(void);
 //---------------------------------------------------------------------------
 // The main program that performs the operations on switches
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    char return_msg[128];           //returned message from 1-wire operations
    short test;                     //info byte data
