$NetBSD: patch-nsmon_nsmon.c,v 1.1 2016/03/13 09:06:01 dholland Exp $

Use standard headers.

--- nsmon/nsmon.c~	1997-03-21 05:14:43.000000000 +0000
+++ nsmon/nsmon.c
@@ -36,6 +36,7 @@
  *
  */
 
+#include <string.h>
 #include "nsmon.h"
 
 /*
