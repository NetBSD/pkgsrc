$NetBSD: patch-filters_pdft.c,v 1.1 2022/12/21 14:41:59 wiz Exp $

Fix compilation on char = signed char systems.

--- filters/pdft.c.orig	2007-02-14 08:42:43.000000000 +0000
+++ filters/pdft.c
@@ -172,7 +172,7 @@ int main(int ac,char *av[]){
 }
 #endif
 
-static char passpadd[] = {
+static unsigned char passpadd[] = {
 	0x28, 0xBF, 0x4E, 0x5E, 0x4E, 0x75, 0x8A, 0x41,
 	0x64, 0x00, 0x4E, 0x56, 0xFF, 0xFA, 0x01, 0x08,
 	0x2E, 0x2E, 0x00, 0xB6, 0xD0, 0x68, 0x3E, 0x80,
@@ -194,7 +194,7 @@ static void setupCrypt(Pdf *pdf,int ver,
 	stdf->p_length = len;
 
 	md5 = newMD5();
-	addMD5(md5,passpadd,32);
+	addMD5(md5,(char*)passpadd,32);
 	addMD5(md5,owner,32);
 	perm[0] = per;
 	perm[1] = per >> 8;
