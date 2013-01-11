$NetBSD: patch-swtloop.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- swtloop.c.orig	2013-01-11 01:31:21.000000000 +0000
+++ swtloop.c
@@ -53,7 +53,7 @@ extern int getkeystroke(void);
 
 //--------------------------------------------------------------------------
 // This is the begining of the program that tests the different Channels
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    char return_msg[128];           //returned message from 1-wire operations
    int i,j,k,n;                    //loop counters
