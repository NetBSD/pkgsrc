$NetBSD: patch-dir.h,v 1.1 2023/06/12 21:41:59 schmonz Exp $

Extract compat definitions for easy inclusion elsewhere.

--- dir.h.orig	2023-06-12 21:25:12.673262635 +0000
+++ dir.h
@@ -641,18 +641,6 @@ static inline int starts_with_dot_dot_sl
 	return path_match_flags(path, what | PATH_MATCH_NATIVE);
 }
 
-#if defined(DT_UNKNOWN) && !defined(NO_D_TYPE_IN_DIRENT)
-#define DTYPE(de)	((de)->d_type)
-#else
-#undef DT_UNKNOWN
-#undef DT_DIR
-#undef DT_REG
-#undef DT_LNK
-#define DT_UNKNOWN	0
-#define DT_DIR		1
-#define DT_REG		2
-#define DT_LNK		3
-#define DTYPE(de)	DT_UNKNOWN
-#endif
+#include "dircompat.h"
 
 #endif
