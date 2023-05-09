$NetBSD: patch-scanner.l,v 1.1 2023/05/09 20:43:22 dholland Exp $

Use correct version comparison logic.

--- CPU/scanner.l~	2010-01-09 05:22:52.000000000 +0000
+++ CPU/scanner.l
@@ -316,7 +316,7 @@ initialize_scanner (FILE *in_file)
   yyin = in_file;
 #ifdef FLEX_SCANNER
   yyrestart(in_file);
-#if (YY_FLEX_MAJOR_VERSION==2 && YY_FLEX_MINOR_VERSION==5 && YY_FLEX_SUBMINOR_VERSION>=33)
+#if (YY_FLEX_MAJOR_VERSION==2 && YY_FLEX_MINOR_VERSION==5 && YY_FLEX_SUBMINOR_VERSION>=33) || (YY_FLEX_MAJOR_VERSION==2 && YY_FLEX_MINOR_VERSION>5)
   /* flex 2.5.33 flipped the polarity of this flag (sigh) */
   yy_init = 0;
 #else
