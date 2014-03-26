$NetBSD: patch-src_sp.cpp,v 1.2 2014/03/26 12:13:17 obache Exp $

* require unistd.h for access(2)
* require string.h for strcat(3) and strcpy(3)

--- src/sp.cpp.orig	2005-05-08 16:11:29.000000000 +0000
+++ src/sp.cpp
@@ -8,6 +8,8 @@
 using namespace scim;
 
 #include <stdio.h>
+#include <unistd.h>
+#include <string.h>
 #include <sys/stat.h>
 #include <limits.h>
 #include <ctype.h>
