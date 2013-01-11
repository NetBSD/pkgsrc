$NetBSD: patch-counter.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- counter.c.orig	2013-01-11 01:30:46.000000000 +0000
+++ counter.c
@@ -60,7 +60,7 @@ uchar FamilySN[MAXDEVICES][8];
 //----------------------------------------------------------------------
 //  Main Test for the DS2423 - counter
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    char return_msg[128];
    int NumDevices=0;
