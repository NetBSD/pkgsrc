$NetBSD: patch-app_main.cpp,v 1.1 2017/02/17 17:09:17 joerg Exp $

Replace operators must be global.

--- app/main.cpp.orig	2017-02-17 12:12:18.536908981 +0000
+++ app/main.cpp
@@ -27,6 +27,43 @@
 #include "system/program.h"
 #include "system/base/io.h"
 
+#if (__GNUC__ == 2 && __GNUC_MINOR__ == 95)
+void* operator new (size_t size) {
+    return AllocMemSafe(size);
+}
+
+void* operator new[] (size_t size) {
+    return AllocMemSafe(size);
+}
+
+void  operator delete (void* ptr) {
+    FreeMemSafe(ptr);
+}
+
+void  operator delete[] (void* ptr) {
+    FreeMemSafe(ptr);
+}
+#endif
+
+#if (__GNUC__ > 2) || defined (_WIN32)
+#include <new>
+void* operator new (size_t size) throw(std::bad_alloc) {
+    return AllocMemSafe(size);
+}
+
+void* operator new[] (size_t size) throw(std::bad_alloc) {
+    return AllocMemSafe(size);
+}
+
+void  operator delete (void* ptr) throw() {
+    FreeMemSafe(ptr);
+}
+
+void  operator delete[] (void* ptr) throw() {
+    FreeMemSafe(ptr);
+}
+#endif
+
 int main(int argc, char **argv)
 {
     Program = CreateProgram(argc, argv);
