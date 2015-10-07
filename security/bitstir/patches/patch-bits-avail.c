$NetBSD: patch-bits-avail.c,v 1.1 2015/10/07 23:19:08 joerg Exp $

--- bits-avail.c.orig	2015-09-27 17:10:12.000000000 +0000
+++ bits-avail.c
@@ -23,14 +23,21 @@
  *           SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
  */
 
+#include <sys/param.h>
 #include <fcntl.h>
 #include <stdio.h>
 #include <sys/ioctl.h>
 #include <sys/rnd.h>
+#if __NetBSD_Version__ >= 799001000
+#  include <sys/rndio.h>
+#endif
+#include <stdlib.h>
+#include <unistd.h>
 
 #define RANDOM "/dev/random"
 
-main()
+int
+main(void)
 {
   int fd, result;
   u_int32_t entropy;
