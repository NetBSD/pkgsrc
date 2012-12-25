$NetBSD: patch-src_fasthenry_sparse_spDefs.h,v 1.1 2012/12/25 21:14:17 joerg Exp $

--- src/fasthenry/sparse/spDefs.h.orig	2012-12-25 16:24:07.000000000 +0000
+++ src/fasthenry/sparse/spDefs.h
@@ -462,14 +462,7 @@ operation of Software or Licensed Progra
  * MEMORY ALLOCATION
  */
 
-extern char *malloc(), *calloc(), *realloc();
-#ifdef ultrix
-    extern void free();
-    extern void abort();
-#else
-    extern free();
-    extern abort();
-#endif
+#include <stdlib.h>
 
 #define ALLOC(type,number)  ((type *)malloc((unsigned)(sizeof(type)*(number))))
 #define REALLOC(ptr,type,number)  \
@@ -909,3 +902,7 @@ struct  MatrixFrame
     struct FillinListNodeStruct *LastFillinListNode;
 };
 typedef  struct MatrixFrame  *MatrixPtr;
+
+void spcLinkRows(MatrixPtr Matrix);
+void spcRowExchange( MatrixPtr Matrix, int Row1, int Row2 );
+void spcColExchange( MatrixPtr Matrix, int Col1, int Col2 );
