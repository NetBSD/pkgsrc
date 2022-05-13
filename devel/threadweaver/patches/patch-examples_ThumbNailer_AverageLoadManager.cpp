$NetBSD: patch-examples_ThumbNailer_AverageLoadManager.cpp,v 1.1 2022/05/13 16:06:46 jperkin Exp $

SunOS needs sys/loadavg.h for getloadavg().

--- examples/ThumbNailer/AverageLoadManager.cpp.orig	2022-04-02 10:06:45.000000000 +0000
+++ examples/ThumbNailer/AverageLoadManager.cpp
@@ -1,3 +1,8 @@
+#ifdef __sun
+#include <sys/time.h>
+#include <sys/loadavg.h>
+#endif
+
 #ifdef Q_OS_UNIX
 #include <stdlib.h>
 #endif
