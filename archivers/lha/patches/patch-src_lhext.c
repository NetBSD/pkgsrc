$NetBSD: patch-src_lhext.c,v 1.1 2020/12/19 15:03:14 rhialto Exp $

utimes() fixes for netbsd-6 time_t

upstream: not reported, docs in .jp only, wakarimasen :(

--- src/lhext.c.orig	2020-12-17 15:59:30.545844796 +0000
+++ src/lhext.c
@@ -220,13 +220,15 @@ adjust_info(name, hdr)
     char           *name;
     LzHeader       *hdr;
 {
-    struct utimbuf utimebuf;
+    struct timeval utimebuf[2];
 
     /* adjust file stamp */
-    utimebuf.actime = utimebuf.modtime = hdr->unix_last_modified_stamp;
+    utimebuf[0].tv_sec = hdr->unix_last_modified_stamp;
+    utimebuf[0].tv_usec = 0;
+    utimebuf[1] = utimebuf[0];
 
     if ((hdr->unix_mode & UNIX_FILE_TYPEMASK) != UNIX_FILE_SYMLINK)
-        utime(name, &utimebuf);
+        utimes(name, &utimebuf[0]);
 
     if (hdr->extend_type == EXTEND_UNIX
         || hdr->extend_type == EXTEND_OS68K
