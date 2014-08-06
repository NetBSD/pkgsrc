$NetBSD: patch-Top_one_file.c,v 1.3 2014/08/06 06:17:07 mrg Exp $

Add NetBSD and DragonFlyBSD support.

--- Top/one_file.c.orig	2014-05-04 04:49:41.000000000 -0700
+++ Top/one_file.c	2014-08-04 22:21:26.000000000 -0700
@@ -29,7 +29,7 @@
 #include <stdlib.h>
 #include "corfile.h"
 
-#if defined(LINUX) || defined(__MACH__) || defined(WIN32)
+#if defined(LINUX) || defined(__MACH__) || defined(WIN32) || defined(__NetBSD__) || defined(__DragonFly__)
 #  include <sys/types.h>
 #  include <sys/stat.h>
 #endif
@@ -62,7 +62,7 @@
 {
 #define   nBytes (256)
     char lbuf[256];
-#if defined(LINUX) || defined(__MACH__)
+#if defined(LINUX) || defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)
     struct stat tmp;
 #elif defined(WIN32)
     struct _stat tmp;
@@ -94,7 +94,7 @@
       }
 #endif
       if (ext != NULL && ext[0] != (char) 0) {
-#if !defined(LINUX) && !defined(__MACH__) && !defined(WIN32)
+#if !defined(LINUX) && !defined(__MACH__) && !defined(WIN32) && !defined(__NetBSD__) && !defined(__DragonFly__)
         char  *p;
         /* remove original extension (does not work on OS X */
         /* and may be a bad idea) */
@@ -114,7 +114,7 @@
           } while (lbuf[i] != '\0');
       }
 #endif
-#if defined(LINUX) || defined(__MACH__)
+#if defined(LINUX) || defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)
       /* if the file already exists, try again */
     } while (stat(lbuf, &tmp) == 0);
 #elif defined(WIN32)
