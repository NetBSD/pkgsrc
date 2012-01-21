$NetBSD: patch-src_wordbuf.c,v 1.1.1.1 2012/01/21 13:38:41 obache Exp $

* include limits.h for INT_MAX const value
  http://code.google.com/p/cmigemo/source/detail?spec=svn4e16f44f91df858b41c39af25798214b1c995a7a&r=49ebb9138cad43520a54e78b93961e6a07fcf422

--- src/wordbuf.c.orig	2011-02-27 10:45:40.000000000 +0000
+++ src/wordbuf.c
@@ -2,13 +2,14 @@
 /*
  * wordbuf.h -
  *
- * Written By:  MURAOKA Taro <koron@tka.att.ne.jp>
- * Last Change: 20-Sep-2009.
+ * Written By:  MURAOKA Taro <koron.kaoriya@gmail.com>
+ * Last Change: 25-Oct-2011.
  */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <limits.h>
 #include "wordbuf.h"
 
 #define WORDLEN_DEF 64
