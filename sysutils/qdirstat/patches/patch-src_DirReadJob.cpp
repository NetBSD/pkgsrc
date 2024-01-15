$NetBSD: patch-src_DirReadJob.cpp,v 1.3 2024/01/15 15:12:47 wiz Exp $

https://github.com/shundhammer/qdirstat/pull/244

--- src/DirReadJob.cpp.orig	2024-01-15 15:08:52.139464419 +0000
+++ src/DirReadJob.cpp
@@ -9,6 +9,7 @@
 
 #include <dirent.h>     // struct dirent
 #include <fcntl.h>	// AT_ constants (fstatat() flags)
+#include <unistd.h>
 
 #include <QMutableListIterator>
 #include <QMultiMap>
