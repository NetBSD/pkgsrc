$NetBSD: patch-mktag.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- mktag.c.orig	2013-01-11 01:31:16.000000000 +0000
+++ mktag.c
@@ -62,7 +62,7 @@ int ReadRoms(FILE *, uchar *, int);
 //----------------------------------------------------------------------
 //  This is the Main routine for list2obm.
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    uchar databuf[MAX_DATABUF];
    int i,j,mcnt,ln;
