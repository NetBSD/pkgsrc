$NetBSD: patch-src_optipng_osys.c,v 1.1 2013/01/11 13:27:53 joerg Exp $

--- src/optipng/osys.c.orig	2013-01-11 01:14:19.000000000 +0000
+++ src/optipng/osys.c
@@ -514,8 +514,13 @@ osys_copy_attr(const char *src_path, con
     {
         struct timespec times[2];
 
+#ifdef __NetBSD__
+        times[0] = sbuf.st_atimespec;
+        times[1] = sbuf.st_mtimespec;
+#else
         times[0] = sbuf.st_atim;
         times[1] = sbuf.st_mtim;
+#endif
         if (utimensat(AT_FDCWD, dest_path, times, 0) != 0)
             return -1;
     }
