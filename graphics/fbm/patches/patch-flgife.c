$NetBSD: patch-flgife.c,v 1.1 2013/02/26 11:13:22 joerg Exp $

--- flgife.c.orig	2013-02-25 17:08:54.000000000 +0000
+++ flgife.c
@@ -57,6 +57,7 @@ static char *fbmid =
 code available free from MLM@CS.CMU.EDU and from UUNET archives$";
 #endif
 
+void compress( int init_bits, FILE *outfile, ifunptr ReadValue );
 
 /*
  * Bump the 'curx' and 'cury' to point to the next pixel
