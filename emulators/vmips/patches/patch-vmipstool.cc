$NetBSD: patch-vmipstool.cc,v 1.1 2011/11/27 19:39:09 joerg Exp $

--- vmipstool.cc.orig	2011-11-27 02:51:38.000000000 +0000
+++ vmipstool.cc
@@ -33,6 +33,9 @@ int getpagesize(void);
 #include <cerrno>
 #include <cstdarg>
 #include <cstdio>
+#include <climits>
+#include <cstdlib>
+#include <cstring>
 #include <iostream>
 #include <sys/stat.h>
 #include <sys/wait.h>
