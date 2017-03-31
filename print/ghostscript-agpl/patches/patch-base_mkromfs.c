$NetBSD: patch-base_mkromfs.c,v 1.1 2017/03/31 07:26:23 adam Exp $

chunk 1:
fix build with _FORTIFY_SOURCE=2; it seems the arguments sometimes
overlap.

chunk 2:
Replace BSD/Linux specific "qd" printf format specifier by "lld",
should fix build problem on Solaris reported by Joern Clausen per PR pkg/40664

--- base/mkromfs.c.orig	2017-03-16 10:12:02.000000000 +0000
+++ base/mkromfs.c
@@ -2014,7 +2014,7 @@ ws(const byte *str, int len)
     if (len >= LINE_SIZE)
         exit(1);
 
-    memcpy(linebuf, str, len);
+    memmove(linebuf, str, len);
     flush_line_buf(len);
 }
 
@@ -2368,7 +2368,7 @@ main(int argc, char *argv[])
     }
     if (!buildtime)
         buildtime = time(NULL);
-    fprintf(out,"    time_t gs_romfs_buildtime = %ld;\n\n", buildtime);
+    fprintf(out,"    time_t gs_romfs_buildtime = %lld;\n\n", (long long)buildtime);
 
     /* process the remaining arguments (options interspersed with paths) */
     for (; atarg < argc; atarg++) {
