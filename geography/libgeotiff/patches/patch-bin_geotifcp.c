$NetBSD: patch-bin_geotifcp.c,v 1.1 2025/05/17 21:00:16 gdt Exp $

Due to build failure on SmartOS because of a type conflict between
getopt being declared directly and the POSIX-required definition
apparently provided by stdlib.h, heavy-handedly modernize to align
with POSIX, including <unistd.h> as specified.
  https://pubs.opengroup.org/onlinepubs/9799919799/functions/getopt.html

Not yet submitted upstream, pending bulk results.

--- bin/geotifcp.c.orig	2025-05-17 20:53:21.317680774 +0000
+++ bin/geotifcp.c
@@ -14,6 +14,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
+#include <unistd.h>
 
 /* GeoTIFF overrides */
 
@@ -37,8 +38,6 @@
 #define	TRUE	1
 #define	FALSE	0
 
-int getopt(int nargc, char** nargv, char* ostr);
-
 static  int outtiled = -1;
 static  uint32_t tilewidth;
 static  uint32_t tilelength;
