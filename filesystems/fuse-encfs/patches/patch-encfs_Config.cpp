$NetBSD: patch-encfs_Config.cpp,v 1.1 2011/11/24 14:11:19 joerg Exp $

--- encfs/Config.cpp.orig	2011-11-24 00:20:46.000000000 +0000
+++ encfs/Config.cpp
@@ -22,6 +22,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <string.h>
 #include <unistd.h>
 
 
