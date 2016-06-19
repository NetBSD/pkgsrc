$NetBSD: patch-bm__unix.c,v 1.1 2016/06/19 16:55:28 tsutsui Exp $

- use <errno.h> for errno.

--- bm_unix.c.orig	2013-08-25 18:59:33.000000000 +0000
+++ bm_unix.c
@@ -27,6 +27,7 @@
 
 
 #include "bmore.h"
+#include <errno.h>
 #include <termios.h>
 
 #define TBUFSIZ 1024
@@ -260,7 +261,6 @@ int
 vgetc()
 {
     char cha;
-    extern int errno;
 
     errno = 0;
     if (read(2, &cha, 1) <= 0) {
