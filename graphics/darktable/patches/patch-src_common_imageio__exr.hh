$NetBSD: patch-src_common_imageio__exr.hh,v 1.1 2013/05/06 14:47:48 joerg Exp $

--- src/common/imageio_exr.hh.orig	2013-05-04 14:59:46.000000000 +0000
+++ src/common/imageio_exr.hh
@@ -21,7 +21,15 @@
 #include "common/image.h"
 #include "common/mipmap_cache.h"
 
+#include <ciso646>
+
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 #include <OpenEXR/ImfFrameBuffer.h>
 #include <OpenEXR/ImfTestFile.h>
@@ -50,7 +58,7 @@ public:
   }
 
   uint32_t size;
-  std::tr1::shared_ptr<uint8_t> data;
+  shared_ptr<uint8_t> data;
 };
 
 
