$NetBSD: patch-dtpstree.cpp,v 1.2 2017/07/08 12:06:56 kamil Exp $

--- dtpstree.cpp.orig	2010-08-05 08:01:47.000000000 +0000
+++ dtpstree.cpp
@@ -21,6 +21,7 @@
 
 #include <cerrno>
 #include <climits>
+#include <clocale>
 #include <cstdarg>
 #include <cstdio>
 #include <cstdlib>
@@ -55,7 +56,9 @@
 #include <pwd.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/user.h>
+#endif
 #include <sys/utsname.h>
 #include <unistd.h>
 #include <vis.h>
