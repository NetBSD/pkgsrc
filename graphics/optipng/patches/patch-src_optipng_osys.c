$NetBSD: patch-src_optipng_osys.c,v 1.2 2014/03/31 07:15:19 adam Exp $

--- src/optipng/osys.c.orig	2014-02-23 16:37:00.000000000 +0000
+++ src/optipng/osys.c
@@ -522,8 +522,13 @@ osys_copy_attr(const char *src_path, con
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
             result = -1;
     }
