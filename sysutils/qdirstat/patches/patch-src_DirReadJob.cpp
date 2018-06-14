$NetBSD: patch-src_DirReadJob.cpp,v 1.1 2018/06/14 00:24:26 markd Exp $

--- src/DirReadJob.cpp.orig	2016-05-16 13:49:54.000000000 +0000
+++ src/DirReadJob.cpp
@@ -11,7 +11,7 @@
 #include <sys/stat.h>
 #include <unistd.h>
 #include <stdio.h>
-#include <sys/errno.h>
+#include <errno.h>
 
 #include <QMutableListIterator>
 
