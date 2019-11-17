$NetBSD: patch-src_openrct2_core_FileStream.hpp,v 1.1 2019/11/17 16:19:57 nia Exp $

Support NetBSD.

--- src/openrct2/core/FileStream.hpp.orig	2019-10-28 20:18:47.000000000 +0000
+++ src/openrct2/core/FileStream.hpp
@@ -128,8 +128,8 @@ public:
     uint64_t GetPosition() const override
     {
 #if defined(_MSC_VER)
-        return _ftelli64(_file);
-#elif (defined(__APPLE__) && defined(__MACH__)) || defined(__ANDROID__) || defined(__OpenBSD__) || defined(__FreeBSD__)
+	return _ftelli64(_file);
+#elif (defined(__APPLE__) && defined(__MACH__)) || defined(__ANDROID__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
         return ftello(_file);
 #else
         return ftello64(_file);
@@ -156,7 +156,7 @@ public:
                 _fseeki64(_file, offset, SEEK_END);
                 break;
         }
-#elif (defined(__APPLE__) && defined(__MACH__)) || defined(__ANDROID__) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#elif (defined(__APPLE__) && defined(__MACH__)) || defined(__ANDROID__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
         switch (origin)
         {
             case STREAM_SEEK_BEGIN:
