$NetBSD: patch-third__party_angle_src_common_system__utils__linux.cpp,v 1.1 2026/08/30 10:26:06 ryoon Exp $

--- third_party/angle/src/common/system_utils_linux.cpp.orig	2026-08-14 22:53:43.182273820 +0000
+++ third_party/angle/src/common/system_utils_linux.cpp
@@ -63,6 +63,10 @@ void SetCurrentThreadName(const char *name)
     // There's a 15-character (16 including '\0') limit.  If the name is too big (and ERANGE is
     // returned), name will be ignored.
     ASSERT(strlen(name) < 16);
+#if defined(__NetBSD__)
+    pthread_setname_np(pthread_self(), "%s", (void *)name);
+#else
     pthread_setname_np(pthread_self(), name);
+#endif
 }
 }  // namespace angle
