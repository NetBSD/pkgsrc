$NetBSD: patch-backends_ninpaths.c,v 1.1 2013/12/11 09:45:14 spz Exp $

--- backends/ninpaths.c.orig	2012-06-15 18:25:36.000000000 +0000
+++ backends/ninpaths.c	2013-12-10 22:08:04.000000000 +0000
@@ -147,7 +147,7 @@ writedump(FILE *f)
     }
     fprintf(f, "!!NINP " VERSION " %lu %lu %ld %ld %ld\n",
             (unsigned long) starttime, (unsigned long) time(NULL), sites,
-            total, (long)(atimes/total)+starttime);
+            total, (long)((atimes/total)+starttime));
     n=j=0;
     /* write the S-records (hosts), numbering them in the process */
     for (i=0; i<HASH_TBL; ++i)
