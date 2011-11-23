$NetBSD: patch-cpm.cpp,v 1.1 2011/11/23 23:27:07 joerg Exp $

--- cpm.cpp.orig	2011-11-23 16:40:21.000000000 +0000
+++ cpm.cpp
@@ -14,6 +14,7 @@
 #include <stdexcept>
 
 #include <stdio.h>
+#include <string.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
