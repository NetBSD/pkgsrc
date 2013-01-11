$NetBSD: patch-tstow.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- tstow.c.orig	2013-01-11 01:31:37.000000000 +0000
+++ tstow.c
@@ -69,7 +69,7 @@ void PrintSerialNum(int portnum);
 //----------------------------------------------------------------------
 //  Main Test
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    int PortNum=1,rslt,i,j,testcnt=0,length;
    uchar TempSerialNum[8];
