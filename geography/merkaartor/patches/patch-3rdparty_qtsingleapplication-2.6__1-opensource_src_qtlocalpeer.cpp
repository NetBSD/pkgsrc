$NetBSD: patch-3rdparty_qtsingleapplication-2.6__1-opensource_src_qtlocalpeer.cpp,v 1.1 2013/05/25 23:43:25 joerg Exp $

--- 3rdparty/qtsingleapplication-2.6_1-opensource/src/qtlocalpeer.cpp.orig	2013-05-25 19:14:26.000000000 +0000
+++ 3rdparty/qtsingleapplication-2.6_1-opensource/src/qtlocalpeer.cpp
@@ -59,6 +59,8 @@ static PProcessIdToSessionId pProcessIdT
 #include <time.h>
 #endif
 
+#include <unistd.h>
+
 namespace QtLP_Private {
 #include "qtlockedfile.cpp"
 #if defined(Q_OS_WIN)
