$NetBSD: patch-coupler.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- coupler.c.orig	2013-01-11 01:31:02.000000000 +0000
+++ coupler.c
@@ -60,7 +60,7 @@ extern int SwitchStateToString1F(int,cha
 // This is the begining of the program that test the commands for the
 // DS2409
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    char return_msg[128];           //returned message from 1-wire operations
    uchar SwitchSN[MAXDEVICES][8];  //the serial numbers for the devices
