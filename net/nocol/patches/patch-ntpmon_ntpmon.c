$NetBSD: patch-ntpmon_ntpmon.c,v 1.1 2016/03/13 09:06:01 dholland Exp $

Use standard headers.

--- ntpmon/ntpmon.c~	1998-08-13 11:42:06.000000000 +0000
+++ ntpmon/ntpmon.c
@@ -24,6 +24,7 @@
  *
  */
 
+#include <string.h>
 #include "ntpmon.h"
 int readconf();
 
