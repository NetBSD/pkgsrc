$NetBSD: patch-source_core_slang-stream.cpp,v 1.1 2026/09/24 18:41:26 ktnb Exp $

NetBSD has ftell(3)

--- source/core/slang-stream.cpp.orig	2026-09-15 12:11:09.000000000 +0000
+++ source/core/slang-stream.cpp
@@ -207,8 +207,8 @@ Int64 FileStream::getPosition()
     fpos_t pos;
     fgetpos(m_handle, &pos);
     return pos;
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__NetBSD__)
     return ftell(m_handle);
 #else
     fpos64_t pos;
     fgetpos64(m_handle, &pos);
