$NetBSD: patch-zoofilt.c,v 1.1 2014/06/29 03:24:33 dholland Exp $

- avoid implicit int
- initialize uninitialized variable

--- zoofilt.c~	1991-07-16 15:59:09.000000000 +0000
+++ zoofilt.c
@@ -34,15 +34,16 @@ int wrint PARMS((unsigned int));	/* writ
 /* global variable used to pass two bytes (CRC value) back from lzd to here */
 unsigned int filt_lzd_word;
 
+extern int lzc(), lzh_encode();					/* possible encoders */
+extern int lzd(), lzh_decode();					/* and decoders */
+
 void zoofilt (option)
 char *option;
 {
-	int choice;											/* what to do -- [de]compress */
+	int choice = 0;											/* what to do -- [de]compress */
 	unsigned int filetag;							/* tag stored in input */
 	int stat1, stat2, stat3;						/* status codes */
 	int use_lzh = 0;									/* use lzh instead */
-	extern lzc(), lzh_encode();					/* possible encoders */
-	extern lzd(), lzh_decode();					/* and decoders */
 
 	while (*++option) {
 		switch (*option) {
