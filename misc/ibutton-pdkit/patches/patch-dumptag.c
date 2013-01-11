$NetBSD: patch-dumptag.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- dumptag.c.orig	2013-01-11 01:31:07.000000000 +0000
+++ dumptag.c
@@ -43,7 +43,7 @@ extern int TAGToString(TAGType *, char *
 //----------------------------------------------------------------------
 //  This is the Main routine for dumpobm.
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    FILE *infp;
    TAGType OutTAG;
