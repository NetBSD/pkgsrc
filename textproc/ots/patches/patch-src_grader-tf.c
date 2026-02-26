$NetBSD: patch-src_grader-tf.c,v 1.1 2026/02/26 01:45:41 gutteridge Exp $

Include math.h for log().

--- src/grader-tf.c.orig	2003-11-26 07:47:48.000000000 +0000
+++ src/grader-tf.c
@@ -18,6 +18,7 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
