$NetBSD: patch-mgdiff.h,v 1.1 2023/03/01 23:48:00 vins Exp $

Pull patches from Debian.

--- mgdiff.h.orig	1994-05-19 02:01:15.000000000 +0000
+++ mgdiff.h
@@ -1,8 +1,8 @@
 #ifndef MXDIFF_H
 #define MXDIFF_H
 
-#ifndef lint
-static char rcsid_mgdiff_h[] = "mgdiff.h,v 2.0 1994/05/19 02:01:15 dan Exp";
+#if 0
+static char rcsid_mgdiff_h[] __attribute__((unused)) = "mgdiff.h,v 2.0 1994/05/19 02:01:15 dan Exp";
 #endif
 
 /*
@@ -52,7 +52,11 @@ typedef struct {
     short *tlen;		/* the lengths of each line */
 } Chunk;
 
-typedef enum {LEFT = 0, RIGHT, NEITHER} Side;
+/*
+** LEFT and RIGHT must be 0 and 1 respectively as they are used 
+** to index as array.
+*/
+typedef enum {LEFT = 0, RIGHT, NEITHER, BOTH} Side;
 
 /* 
  * a block is an element of a doubly linked list containing a left chunk 
@@ -86,4 +90,27 @@ typedef struct {
  */
 #define X11R5 (defined(XtSpecificationRelease) && (XtSpecificationRelease >= 5))
 
+#include <string.h>
+#include <stdlib.h>
+static inline char* xstrdup(const char *s)
+{
+    char *ret = strdup(s);
+    if (!ret) {
+        perror("strdup");
+        exit (1);
+    }
+    return ret;
+}
+
+/*
+ * According to IETF RFC 2279, byte values of 0xfe and 0xff are
+ * not legal utf-8, but all others bytes are legal.
+ */
+#if 1
+#define islatin(c)     (isprint((c)) || ((((unsigned char)(c)) <= 0xfd)))
+#define isallowed(c)	(isascii((c)) || islatin((c)))
+#else
+#define islatin(c)	((isprint((c)) || ((((unsigned int)(c)) >= 160) && (((unsigned int)(c)) <= 255))))
+#define isallowed(c)	(isascii((c)) || islatin((c)))
+#endif
 #endif
