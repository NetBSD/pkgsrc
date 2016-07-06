$NetBSD: patch-otherlibs_bigarray_mmap__unix.c,v 1.1 2016/07/06 14:19:51 jperkin Exp $

Avoid incompatible _XOPEN_SOURCE definition on SunOS.

--- otherlibs/bigarray/mmap_unix.c.orig	2016-04-25 13:36:01.000000000 +0000
+++ otherlibs/bigarray/mmap_unix.c
@@ -15,7 +15,9 @@
 
 /* Needed (under Linux at least) to get pwrite's prototype in unistd.h.
    Must be defined before the first system .h is included. */
+#ifndef __sun
 #define _XOPEN_SOURCE 500
+#endif
 
 #include <stddef.h>
 #include <string.h>
