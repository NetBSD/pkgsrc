$NetBSD: patch-rpc2-src_stest.c,v 1.1 2012/04/19 21:04:02 joerg Exp $

--- rpc2-src/stest.c.orig	2012-04-19 13:51:58.000000000 +0000
+++ rpc2-src/stest.c
@@ -94,9 +94,7 @@ long VMMaxFileSize; /* length of VMFileB
 long VMCurrFileSize; /* number of useful bytes in VMFileBuf */
 char *VMFileBuf;    /* for FILEINVM transfers */
 
-int main(argc, argv)
-    long argc;
-    char *argv[];
+int main(int argc, char *argv[])
 {
     SFTP_Initializer sftpi;
 
