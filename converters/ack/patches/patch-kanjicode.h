$NetBSD: patch-kanjicode.h,v 1.1 2012/12/26 21:21:38 dholland Exp $

- don't randomly use unsigned char for ordinary strings
- move external declarations to header files
- declare own functions
- don't truncate time_t

--- kanjicode.h.orig	1994-07-20 05:13:28.000000000 +0000
+++ kanjicode.h
@@ -1,5 +1,8 @@
 /*	Copyright 1993 H.Ogasawara (COR.)	*/
 
+#include <stddef.h>
+#include <time.h>
+
 /* v1.00  1993 10/10	*/
 /* v1.10  1994  3/19	*/
 /* v1.20  1994  3/21	*/
@@ -37,12 +40,12 @@ typedef struct {
 	int	flag,
 		inpcode,
 		outcode,
-		files,
-		time;
+		files;
+	time_t	time;
 	unsigned char	*kanjicheck_h;
 	unsigned int	(*kanjitocode)(),
 			(*codetokanji)();
-	unsigned char	fname[PATHLEN];
+	char	fname[PATHLEN];
 } T_KANJI;
 
 #define	ROMA	0
@@ -62,3 +65,11 @@ typedef struct {
 #  define DEFCODE	1
 #endif
 
+extern unsigned char	sjischeck_h[],
+			euccheck_h[];
+
+void CodeCheckAll(T_KANJI *cp);
+void SjisEucConvert(T_KANJI *cp);
+
+/* lcode.c */
+void SjisEucCheck(unsigned char *ptr, size_t len, T_KANJI *cp);
