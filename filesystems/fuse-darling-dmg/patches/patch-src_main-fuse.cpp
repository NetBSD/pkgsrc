--- src/main-fuse.cpp.orig	2016-03-10 17:36:33.000000000 +0100
+++ src/main-fuse.cpp	2016-03-10 17:36:50.000000000 +0100
@@ -2,7 +2,7 @@
 #include <cstring>
 #include <iostream>
 #include <cstdio>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #else
 #include <endian.h>
