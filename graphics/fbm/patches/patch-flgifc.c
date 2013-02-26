$NetBSD: patch-flgifc.c,v 1.1 2013/02/26 11:13:22 joerg Exp $

--- flgifc.c.orig	2013-02-25 17:08:02.000000000 +0000
+++ flgifc.c
@@ -168,10 +168,7 @@ static char *fbmid =
 code available free from MLM@CS.CMU.EDU and from UUNET archives$";
 #endif
 
-compress( init_bits, outfile, ReadValue )
-int init_bits;
-FILE *outfile;
-ifunptr ReadValue;
+void compress( int init_bits, FILE *outfile, ifunptr ReadValue )
 {
     register long fcode;
     register code_int i = 0;
