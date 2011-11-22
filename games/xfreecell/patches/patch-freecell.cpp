$NetBSD: patch-freecell.cpp,v 1.1 2011/11/22 18:11:14 joerg Exp $

--- freecell.cpp.orig	2011-11-22 17:06:14.000000000 +0000
+++ freecell.cpp
@@ -1,6 +1,7 @@
 #include <dirent.h>
 #include <fcntl.h>
 #include <stdlib.h>
+#include <string.h>
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/types.h>
