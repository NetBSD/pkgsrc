$NetBSD: patch-src_io_inkjar.cpp,v 1.1 2014/05/08 21:52:40 asau Exp $

--- src/io/inkjar.cpp.orig	2012-02-14 03:22:17.670697000 +0000
+++ src/io/inkjar.cpp
@@ -42,6 +42,8 @@
 #include <fcntl.h>
 //#endif
 
+#include <unistd.h>
+
 #include <cstring>
 #include <string>
 #include <cstdlib>
