$NetBSD: patch-src_table.cpp,v 1.1 2013/03/25 12:55:04 obache Exp $

* require unistd.h for access(2)

--- src/table.cpp.orig	2005-05-08 16:11:29.000000000 +0000
+++ src/table.cpp
@@ -19,6 +19,7 @@ using namespace scim;
 
 
 #include <stdio.h>
+#include <unistd.h>
 #include <sys/stat.h>
 #include <string.h>
 #include <stdlib.h>
