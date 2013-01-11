$NetBSD: patch-tstowe.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- tstowe.c.orig	2013-01-11 01:31:39.000000000 +0000
+++ tstowe.c
@@ -67,7 +67,7 @@ void PrintSerialNum(int);
 //----------------------------------------------------------------------
 //  Main Test
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    int PortNum=1,rslt,i,testcnt=0,length,pg;
    uchar tran_buffer[2000];
