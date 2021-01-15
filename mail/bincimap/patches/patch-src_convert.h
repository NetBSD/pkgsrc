$NetBSD: patch-src_convert.h,v 1.2 2021/01/15 22:01:29 schmonz Exp $

Fix "assigning to 'char *' from incompatible type 'const char *'".

Fix "error: 'strchr' was not declared in this scope" on at least NetBSD
and Tribblix.

Fix "error: '::atoi' has not been declared" on at least CentOS 7.

--- src/convert.h.orig	2005-02-08 20:30:22.000000000 +0000
+++ src/convert.h
@@ -43,6 +43,8 @@
 #include <iostream>
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <sys/stat.h>
 
 #include "address.h"
@@ -111,7 +113,7 @@ namespace Binc {
       unsigned char c = *i;
       unsigned char d = *(i + 1);
       
-      char *t;
+      const char *t;
       if ((t = strchr(hexchars, c)) == 0)
 	return "out of range";
       n = (t - hexchars) << 4;
