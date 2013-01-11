$NetBSD: patch-atodtst.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- atodtst.c.orig	2013-01-11 01:30:30.000000000 +0000
+++ atodtst.c
@@ -80,7 +80,7 @@ uchar FamilySN[MAXDEVICES][8];
 //----------------------------------------------------------------------
 //  Main Test for the DS2450 - 1-Wire Quad A/D Converter
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    char return_msg[128];
    char msg[45];
