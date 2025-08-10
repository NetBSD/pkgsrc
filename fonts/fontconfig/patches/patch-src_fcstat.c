$NetBSD: patch-src_fcstat.c,v 1.8 2025/08/10 13:58:35 ryoon Exp $

The argument types to scandir(3) differ between different OSes.
I used the provided alphasort instead of rewriting the equivalent
sorter function.

--- src/fcstat.c.orig	2025-07-02 04:46:34.000000000 +0000
+++ src/fcstat.c
@@ -337,6 +337,9 @@ FcStatChecksum (const FcChar8 *file, str
 	    return -1;
     }
 #endif
+#if defined(_SCO_DS)
+#include "../scandir.c"
+#endif
 
     return 0;
 }
