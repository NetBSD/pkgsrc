$NetBSD: patch-common_conv.c,v 1.1 2013/02/08 23:09:18 christos Exp $

Don't fail if a character conversion failed; insert the raw characters
into the file instead.

--- common/conv.c.orig	2007-11-18 11:41:42.000000000 -0500
+++ common/conv.c	2013-02-08 18:04:36.000000000 -0500
@@ -60,6 +60,21 @@
     return 0;
 }
 
+#ifndef ERROR_ON_CONVERT
+#define HANDLE_ICONV_ERROR(o, i, ol, il) do {				\
+		*o++ = *i++;						\
+		ol--; il--;						\
+	} while (/*CONSTCOND*/0)
+#define HANDLE_MBR_ERROR(n, mbs, d, s) do {				\
+		d = s;							\
+		MEMSET(&mbs, 0, 1); 					\
+		n = 1; 							\
+	} while (/*CONSTCOND*/0)
+#else
+#define HANDLE_ICONV_ERROR goto err
+#define	HANDLE_MBR_ERROR goto err
+#endif
+
 #define CONV_BUFFER_SIZE    512
 /* fill the buffer with codeset encoding of string pointed to by str
  * left has the number of bytes left in str and is adjusted
@@ -72,9 +87,9 @@
 	char *bp = buffer;						\
 	outleft = CONV_BUFFER_SIZE;					\
 	errno = 0;							\
-	if (iconv(id, (char **)&str, &left, &bp, &outleft) == -1 /*&&	\
-		errno != E2BIG*/)					\
-	    goto err;							\
+	if (iconv(id, (const char **)&str, &left, &bp, &outleft) 	\
+	    == (size_t)-1 /* && errno != E2BIG */)			\
+		HANDLE_ICONV_ERROR(bp, str, outleft, left);		\
 	if ((len = CONV_BUFFER_SIZE - outleft) == 0) {			\
 	    error = -left;						\
 	    goto err;							\
@@ -116,8 +131,9 @@
     for (i = 0, j = 0; j < len; ) {
 	n = mbrtowc((*tostr)+i, src+j, len-j, &mbs);
 	/* NULL character converted */
-	if (n == -2) error = -(len-j);
-	if (n == -1 || n == -2) goto err;
+ 	if (n == (size_t)-2) error = -(len-j);
+	if (n == (size_t)-1 || n == (size_t)-2)
+	    HANDLE_MBR_ERROR(n, mbs, (*tostr)[i], src[j]); 
 	if (n == 0) n = 1;
 	j += n;
 	if (++i >= *blen) {
@@ -238,8 +254,9 @@
 		BINC_RETC(NULL, cw->bp1, cw->blen1, nlen);		\
 	    }						    		\
 	    errno = 0;						    	\
-	    if (iconv(id, &bp, &len, &obp, &outleft) == -1 && 	        \
-		    errno != E2BIG)					\
+	    if (iconv(id, &bp, &len, &obp, &outleft) == (size_t)-1 &&	\
+		errno != E2BIG) 					\
+		    HANDLE_ICONV_ERROR(obp, bp, outleft, len);		\
 		goto err;						\
 	    offset = cw->blen1 - outleft;			        \
 	}							        \
@@ -264,7 +281,8 @@
 
     for (i = 0, j = 0; i < len; ++i) {
 	n = wcrtomb(dst+j, str[i], &mbs);
-	if (n == -1) goto err;
+	if (n == (size_t)-1) 
+	   HANDLE_MBR_ERROR(n, mbs, dst[j], str[i]);
 	j += n;
 	if (buflen < j + MB_CUR_MAX) {
 	    if (id != (iconv_t)-1) {
