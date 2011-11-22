$NetBSD: patch-src-fifo.cpp,v 1.1 2011/11/22 18:02:31 joerg Exp $

--- src/fifo.cpp.orig	2011-11-22 17:36:31.000000000 +0000
+++ src/fifo.cpp
@@ -29,6 +29,7 @@
 #include <stdlib.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <limits.h>
 #include <ctype.h>
 #include "time-fix.h"
 
