$NetBSD: patch-base_mutex.h,v 1.2 2013/01/26 20:33:59 ryoon Exp $

* First chunk, NetBSD ILP32 ports seem to require larger mutex array size.
* I am not sure.

--- base/mutex.h.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/mutex.h
@@ -46,8 +46,8 @@ namespace mozc {
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
@@ -56,6 +56,10 @@ namespace mozc {
 #define MOZC_RW_MUTEX_PTR_ARRAYSIZE 10
 #endif
 
+#if defined(__FreeBSD__) || defined(OS_NETBSD)
+#define PTHREAD_MUTEX_RECURSIVE_VALUE PTHREAD_MUTEX_RECURSIVE
+#endif
+
 class LOCKABLE Mutex {
  public:
   Mutex();
