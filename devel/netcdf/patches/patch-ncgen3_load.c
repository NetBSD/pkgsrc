$NetBSD: patch-ncgen3_load.c,v 1.1 2015/08/28 18:14:42 wiedi Exp $

fix build on osx with clang. The fix will also be in the next release.
Details: http://www.unidata.ucar.edu/software/netcdf/docs/known_problems.html#clang-ncgen3

--- ncgen3/load.c.orig	2012-08-03 20:12:20.000000000 +0000
+++ ncgen3/load.c
@@ -5,6 +5,7 @@
  *********************************************************************/
 
 #include <stdio.h>
+#include <config.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
