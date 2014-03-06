$NetBSD: patch-Top_one_file.c,v 1.1 2014/03/06 10:16:53 mrg Exp $

--- Top/one_file.c.orig	2014-01-07 08:54:20.000000000 -0800
+++ Top/one_file.c	2014-02-12 23:53:28.000000000 -0800
@@ -29,7 +29,7 @@
 #include <stdlib.h>
 #include "corfile.h"
 
-#if defined(LINUX) || defined(__MACH__) || defined(WIN32)
+#if defined(LINUX) || defined(__MACH__) || defined(WIN32) || defined(__NetBSD__) || defined(__DragonFly__)
 #  include <sys/types.h>
 #  include <sys/stat.h>
 #endif
@@ -77,7 +77,7 @@
 {
     size_t  nBytes = 256;
     char lbuf[256];
-#if defined(LINUX) || defined(__MACH__)
+#if defined(LINUX) || defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)
     struct stat tmp;
 #elif defined(WIN32)
     struct _stat tmp;
@@ -109,7 +109,7 @@
       }
 #endif
       if (ext != NULL && ext[0] != (char) 0) {
-#if !defined(LINUX) && !defined(__MACH__) && !defined(WIN32)
+#if !defined(LINUX) && !defined(__MACH__) && !defined(WIN32) && !defined(__NetBSD__) && !defined(__DragonFly__)
         char  *p;
         /* remove original extension (does not work on OS X */
         /* and may be a bad idea) */
@@ -129,7 +129,7 @@
           } while (lbuf[i] != '\0');
       }
 #endif
-#if defined(LINUX) || defined(__MACH__)
+#if defined(LINUX) || defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)
       /* if the file already exists, try again */
     } while (stat(lbuf, &tmp) == 0);
 #elif defined(WIN32)
