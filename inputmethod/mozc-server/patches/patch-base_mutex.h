$NetBSD: patch-base_mutex.h,v 1.2 2016/05/16 11:51:49 ryoon Exp $

* First chunk, NetBSD ILP32 ports seem to require larger mutex array size.
* I am not sure.

--- base/mutex.h.orig	2016-05-15 08:11:10.000000000 +0000
+++ base/mutex.h
@@ -50,8 +50,8 @@ namespace mozc {
 // To remove dependencies against plafrom specific headers such as
 // <Windows.h> or <pthread.h>, we use an array of pointers as an opaque buffer
 // where platform specific mutex structure will be placed.
-#if defined(OS_MACOSX)
-// Mac requires relatively large buffer for pthread mutex object.
+#if defined(OS_MACOSX) || defined(OS_NETBSD)
+// Mac and NetBSD requires relatively large buffer for pthread mutex object.
 #define MOZC_MUTEX_PTR_ARRAYSIZE 11
 #define MOZC_RW_MUTEX_PTR_ARRAYSIZE 32
 #else
