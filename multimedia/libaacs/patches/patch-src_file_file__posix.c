$NetBSD: patch-src_file_file__posix.c,v 1.1 2014/01/08 23:04:43 wiz Exp $

fseeko/ftello are Linuxisms.

--- src/file/file_posix.c.orig	2013-12-18 09:21:16.000000000 +0000
+++ src/file/file_posix.c
@@ -49,7 +49,7 @@ static int64_t file_seek_linux(AACS_FILE
 #if defined(__MINGW32__)
     return fseeko64((FILE *)file->internal, offset, origin);
 #else
-    return fseeko((FILE *)file->internal, offset, origin);
+    return fseek((FILE *)file->internal, offset, origin);
 #endif
 }
 
@@ -58,7 +58,7 @@ static int64_t file_tell_linux(AACS_FILE
 #if defined(__MINGW32__)
     return ftello64((FILE *)file->internal);
 #else
-    return ftello((FILE *)file->internal);
+    return ftell((FILE *)file->internal);
 #endif
 }
 
