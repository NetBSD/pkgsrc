$NetBSD: patch-base_port.h,v 1.4 2017/12/17 14:15:43 tsutsui Exp $

* NetBSD support
* kludge to build with gcc45

--- base/port.h.orig	2017-11-02 13:32:45.000000000 +0000
+++ base/port.h
@@ -56,6 +56,9 @@
 #endif  // !OS_ANDROID && !OS_NACL
 #endif  // OS_LINUX
 
+#ifdef OS_NETBSD
+#define MOZC_OS_DEFINED
+#endif  // OS_NETBSD
 
 #ifndef MOZC_OS_DEFINED
 #error "OS_XXX (e.g., OS_WIN) must be defined."
@@ -154,4 +157,9 @@ static const  int64 kint64max  = (( int6
 #define AS_STRING(x)   AS_STRING_INTERNAL(x)
 #define AS_STRING_INTERNAL(x)   #x
 
+// gcc>=46 has nullptr, otherwise use __null instead.
+#if __cplusplus < 201103L && !defined(__clang__) && defined(__GNUC__) && __GNUC__ * 1000 + __GNUC__MINOR__ < 4006
+#define nullptr __null
+#endif
+
 #endif  // MOZC_BASE_PORT_H_
