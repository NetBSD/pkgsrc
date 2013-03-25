$NetBSD: patch-src_py.cpp,v 1.1 2013/03/25 12:55:04 obache Exp $

* require unistd.h for access(2)

--- src/py.cpp.orig	2005-05-08 16:11:28.000000000 +0000
+++ src/py.cpp
@@ -8,6 +8,7 @@
 using namespace scim;
 
 #include <stdio.h>
+#include <unistd.h>
 #include <sys/stat.h>
 #include <limits.h>
 #include <stdlib.h>
