$NetBSD: patch-swtsngl.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- swtsngl.c.orig	2013-01-11 01:31:26.000000000 +0000
+++ swtsngl.c
@@ -48,7 +48,7 @@ extern int ReadSwitch05(int,uchar *,int 
 // This is the begining of the program that tests the commands for the
 // DS2405
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    char return_msg[128];           //returned message from 1-wire operations
    uchar SwitchSN[MAXDEVICES][8];  //the serial numbers for the devices
