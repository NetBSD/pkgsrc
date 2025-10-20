$NetBSD: patch-src_lib_platform_XWindowsClipboard.cpp,v 1.1 2025/10/20 19:49:13 tnn Exp $

Avoid requirement on newer compiler for now.
GCC 12 claims C++20 but has incomplete <format> support.
Reverts: https://github.com/deskflow/deskflow/commit/023037f7ee6bbb09844f4cc146734f1ecaa17a27

--- src/lib/platform/XWindowsClipboard.cpp.orig	2025-09-11 14:59:52.000000000 +0000
+++ src/lib/platform/XWindowsClipboard.cpp
@@ -21,7 +21,9 @@
 #include <algorithm>
 #include <cstdio>
 #include <cstring>
+#if 0
 #include <format>
+#endif
 #include <vector>
 
 //
@@ -637,7 +639,11 @@ void XWindowsClipboard::motifFillCache()
   // get the Motif item property from the root window
   static const int buffer_size = 18 + 20;
   char name[buffer_size];
+#if 0
   std::format_to_n(name, buffer_size, "_MOTIF_CLIP_ITEM_{}", header.m_item);
+#else
+  snprintf(name, buffer_size, "_MOTIF_CLIP_ITEM_%d", header.m_item);
+#endif
   Atom atomItem = XInternAtom(m_display, name, False);
   data = "";
   if (!XWindowsUtil::getWindowProperty(m_display, root, atomItem, &data, &target, &format, False)) {
@@ -662,7 +668,11 @@ void XWindowsClipboard::motifFillCache()
   MotifFormatMap motifFormats;
   for (int32_t i = 0; i < numFormats; ++i) {
     // get Motif format property from the root window
+#if 0
     std::format_to_n(name, buffer_size, "_MOTIF_CLIP_ITEM_{}", formats[i]);
+#else
+    snprintf(name, buffer_size, "_MOTIF_CLIP_ITEM_%d", formats[i]);
+#endif
     Atom atomFormat = XInternAtom(m_display, name, False);
     std::string data;
     if (!XWindowsUtil::getWindowProperty(m_display, root, atomFormat, &data, &target, &format, False)) {
@@ -737,7 +747,11 @@ bool XWindowsClipboard::motifGetSelectio
   // part that i don't know.
   static const int buffer_size = 18 + 20;
   char name[buffer_size];
+#if 0
   std::format_to_n(name, buffer_size, "_MOTIF_CLIP_ITEM_{}", format->m_data);
+#else
+  snprintf(name, buffer_size, "_MOTIF_CLIP_ITEM_%d", format->m_data);
+#endif
   Atom target = XInternAtom(m_display, name, False);
   Window root = RootWindow(m_display, DefaultScreen(m_display));
   return XWindowsUtil::getWindowProperty(m_display, root, target, data, actualTarget, nullptr, False);
