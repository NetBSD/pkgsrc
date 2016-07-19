$NetBSD: patch-src--vp8--model--jpeg_meta.hh,v 1.1 2016/07/19 02:11:51 agc Exp $

Port to BSD-based systems

--- src/vp8/model/jpeg_meta.hh	2016/07/17 17:54:51	1.1
+++ src/vp8/model/jpeg_meta.hh	2016/07/17 17:55:35
@@ -4,8 +4,11 @@
 #include <vector>
 #include <type_traits>
 #ifndef __APPLE__
-#ifndef BSD
 #ifndef _WIN32
+#include <sys/param.h>
+#if (defined(BSD) && BSD >= 199506)
+#include <sys/endian.h>
+#else
 #include <endian.h>
 #endif
 #endif
