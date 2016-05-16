$NetBSD: patch-base_port.h,v 1.3 2016/05/16 11:51:49 ryoon Exp $

--- base/port.h.orig	2016-05-15 08:11:10.000000000 +0000
+++ base/port.h
@@ -56,6 +56,10 @@
 #endif  // !OS_ANDROID && !OS_NACL
 #endif  // OS_LINUX
 
+#ifdef OS_NETBSD
+#define MOZC_OS_DEFINED
+#endif  // OS_NETBSD
+
 #ifndef MOZC_OS_DEFINED
 #error "OS_XXX (e.g., OS_WIN) must be defined."
 #endif  // !MOZC_OS_DEFINED
@@ -157,4 +161,9 @@ static const  int64 kint64max  = (( int6
 #define AS_STRING(x)   AS_STRING_INTERNAL(x)
 #define AS_STRING_INTERNAL(x)   #x
 
+// gcc>=46 has nullptr, otherwise use __null instead.
+#if __cplusplus < 201103L && !defined(__clang__) && defined(__GNUC__) && __GNUC__ * 1000 + __GNUC__MINOR__ < 4006
+#define nullptr __null
+#endif
+
 #endif  // MOZC_BASE_PORT_H_
