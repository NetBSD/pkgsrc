$NetBSD: patch-src_gdt.h,v 1.1 2012/12/21 10:29:47 dholland Exp $

Add a name for const char * to go with the other pointless typedef
names in here.

--- src/gdt.h~	2000-02-04 23:10:40.000000000 +0000
+++ src/gdt.h
@@ -62,6 +62,7 @@ typedef FLOAT*        PFLOAT;
 typedef double        DOUBLE;
 typedef char          CHR;
 typedef CHR*          PCHR;
+typedef const CHR*    PKCHR;
 typedef CHR**         PPCHR;
 typedef unsigned char UCHR;
 typedef UCHR*         PUCHR;
