$NetBSD: patch-xvbmp.c,v 1.1 2025/04/19 23:14:24 tsutsui Exp $

- Pull fixes from https://gitlab.com/DavidGriffith/xv
 - https://gitlab.com/DavidGriffith/xv/-/commit/60a25db1
   > Updated xvbmp.c to support reading the three newer versions of BMP format.

--- xvbmp.c.orig	2025-04-19 20:57:51.312309284 +0000
+++ xvbmp.c
@@ -27,8 +27,11 @@
 #define BI_PNG       5   /* BMP version 5 (not yet supported) */
 
 #define WIN_OS2_OLD 12
-#define WIN_NEW     40
 #define OS2_NEW     64
+#define WIN_3X      40
+#define WIN_95_NT4  108
+#define WIN_98_2K   124
+#define WIN_NT_2K   128
 
 #if (defined(UINT_MAX) && UINT_MAX != 0xffffffffU)
 #  error XV's BMP code requires 32-bit unsigned integer type, but u_int isn't
@@ -95,7 +98,8 @@ int LoadBMP(fname, pinfo)
 
   biSize          = getint(fp);
 
-  if (biSize == WIN_NEW || biSize == OS2_NEW) {
+  if (biSize == WIN_3X || biSize == OS2_NEW ||
+	biSize == WIN_95_NT4 || biSize == WIN_98_2K || biSize == WIN_NT_2K) {
     biWidth         = getint(fp);
     biHeight        = getint(fp);
     biPlanes        = getshort(fp);
@@ -315,8 +319,12 @@ int LoadBMP(fname, pinfo)
   pinfo->colType = F_FULLCOLOR;
 
   sprintf(pinfo->fullInfo, "%sBMP, %d bit%s per pixel%s.  (%ld bytes)",
-	  ((biSize==WIN_OS2_OLD) ? "Old OS/2 " :
-	   (biSize==WIN_NEW)     ? "Windows "  : ""),
+	  ((biSize==WIN_OS2_OLD) ? "OS/2 1.x " :
+	   (biSize==OS2_NEW)     ? "OS/2 2.x " :
+	   (biSize==WIN_3X)      ? "Windows 3.x "  :
+	   (biSize==WIN_95_NT4)  ? "Windows 95/NT4 " :
+	   (biSize==WIN_98_2K)   ? "Windows 98/2000" :
+	   (biSize==WIN_NT_2K)   ? "Windows NT/2000 " : ""),
 	  biBitCount,  (biBitCount == 1) ? "" : "s",
 	  cmpstr, filesize);
 
