$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_wtf_Atomics.h,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/Atomics.h.orig	2016-08-23 06:13:30.000000000 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/Atomics.h
@@ -69,6 +69,8 @@
 #include <cutils/atomic.h>
 #elif OS(QNX)
 #include <atomic.h>
+#elif __cplusplus >= 201103L
+#include <atomic>
 #elif COMPILER(GCC) && !OS(SYMBIAN)
 #if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))
 #include <ext/atomicity.h>
@@ -106,6 +108,11 @@ inline int atomicDecrement(int volatile*
 inline int atomicIncrement(int volatile* addend) { return (int) atomic_add_value((unsigned int volatile*)addend, 1); }
 inline int atomicDecrement(int volatile* addend) { return (int) atomic_sub_value((unsigned int volatile*)addend, 1); }
 
+#elif __cplusplus >= 201103L
+#define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
+inline int atomicIncrement(std::atomic<int> * addend) { return *addend++; }
+inline int atomicDecrement(std::atomic<int> * addend) { return *addend--; }
+
 #elif COMPILER(GCC) && !CPU(SPARC64) && !OS(SYMBIAN) // sizeof(_Atomic_word) != sizeof(int) on sparc64 gcc
 #define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
 
@@ -114,9 +121,15 @@ inline int atomicDecrement(int volatile*
 
 #endif
 
+#if !OS(DARWIN) && __cplusplus >= 201103L
+typedef std::atomic<int> atomic_int;
+#else
+typedef int volatile atomic_int;
+#endif
 } // namespace WTF
 
 #if USE(LOCKFREE_THREADSAFEREFCOUNTED)
+using WTF::atomic_int;
 using WTF::atomicDecrement;
 using WTF::atomicIncrement;
 #endif
