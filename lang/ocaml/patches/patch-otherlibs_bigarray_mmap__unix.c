$NetBSD: patch-otherlibs_bigarray_mmap__unix.c,v 1.2 2016/12/30 11:15:00 jaapb Exp $

Avoid incompatible _XOPEN_SOURCE definition on SunOS.

--- otherlibs/bigarray/mmap_unix.c.orig	2016-09-05 13:19:52.000000000 +0000
+++ otherlibs/bigarray/mmap_unix.c
@@ -17,7 +17,9 @@
 
 /* Needed (under Linux at least) to get pwrite's prototype in unistd.h.
    Must be defined before the first system .h is included. */
+#ifndef __sun
 #define _XOPEN_SOURCE 600
+#endif
 
 #include <stddef.h>
 #include <string.h>
