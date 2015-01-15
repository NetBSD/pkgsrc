$NetBSD: patch-src_extractors_ffmpegextractor.cpp,v 1.1 2015/01/15 17:58:16 rumko Exp $

On FreeBSD, UINT64_C & co. are protected by _MACHINE__STDINT_H_

--- src/extractors/ffmpegextractor.cpp.orig	2014-07-18 08:06:55.000000000 +0000
+++ src/extractors/ffmpegextractor.cpp
@@ -29,6 +29,9 @@
 #ifdef _STDINT_H
 #undef _STDINT_H
 #endif
+#ifdef _MACHINE__STDINT_H_
+#undef _MACHINE__STDINT_H_
+#endif
 # include <stdint.h>
 #endif
 
