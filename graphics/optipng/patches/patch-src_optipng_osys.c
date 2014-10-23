$NetBSD: patch-src_optipng_osys.c,v 1.3 2014/10/23 12:24:41 adam Exp $

Compatibility fix.

--- src/optipng/osys.c.orig	2014-02-23 16:37:00.000000000 +0000
+++ src/optipng/osys.c
@@ -518,12 +518,17 @@ osys_copy_attr(const char *src_path, con
     if (chmod(dest_path, sbuf.st_mode) != 0)
         result = -1;
 
-#ifdef AT_FDCWD
+#if defined(AT_FDCWD) && !defined(__APPLE__)
     {
         struct timespec times[2];
 
+#if defined(__NetBSD__)
+        times[0] = sbuf.st_atimespec;
+        times[1] = sbuf.st_mtimespec;
+#else
         times[0] = sbuf.st_atim;
         times[1] = sbuf.st_mtim;
+#endif
         if (utimensat(AT_FDCWD, dest_path, times, 0) != 0)
             result = -1;
     }
