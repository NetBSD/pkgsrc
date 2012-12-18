$NetBSD: patch-ak,v 1.2 2012/12/18 14:42:29 jperkin Exp $

* On DragonFly, FILE is hidden, only allowed to modify in __FILE_public.

* Disable file-type pipe detection on 64-bit Solaris.

--- src/formats.c.orig	2012-03-04 22:54:16.000000000 +0000
+++ src/formats.c	2012-12-18 14:37:03.629252407 +0000
@@ -406,17 +406,22 @@
 /* _FSTDIO is for Torek stdio (i.e. most BSD-derived libc's)
  * In theory, we no longer need to check _NEWLIB_VERSION or __APPLE__ */
 #if defined _FSTDIO || defined _NEWLIB_VERSION || defined __APPLE__
+#  ifdef __DragonFly__
+  struct __FILE_public *fpp = (struct __FILE_public *)fp;
+  fpp->_p -= AUTO_DETECT_SIZE;
+  fpp->_r += AUTO_DETECT_SIZE;
+#  else
   fp->_p -= AUTO_DETECT_SIZE;
   fp->_r += AUTO_DETECT_SIZE;
+#  endif
 #elif defined __GLIBC__
   fp->_IO_read_ptr = fp->_IO_read_base;
-#elif defined _MSC_VER || defined __MINGW_H || defined _ISO_STDIO_ISO_H
+#elif defined _MSC_VER || defined __MINGW_H || (defined _ISO_STDIO_ISO_H && !(defined(__sun) && defined(_LP64)))
   fp->_ptr = fp->_base;
 #else
   /* To fix this #error, either simply remove the #error line and live without
    * file-type detection with pipes, or add support for your compiler in the
    * lines above.  Test with cat monkey.au | ./sox --info - */
-  #error FIX NEEDED HERE
   #define NO_REWIND_PIPE
   (void)fp;
 #endif
