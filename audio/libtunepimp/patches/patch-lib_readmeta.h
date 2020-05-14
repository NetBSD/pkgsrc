$NetBSD: patch-lib_readmeta.h,v 1.1 2020/05/14 19:03:12 joerg Exp $

--- lib/readmeta.h.orig	2020-05-13 19:40:43.479981206 +0000
+++ lib/readmeta.h
@@ -30,7 +30,7 @@
 #include <string>
 using namespace std;
 #include "thread.h"
-#include "semaphore.h"
+#include "semaphore_.h"
 #include "track.h"
 #include "plugin.h"
 
