$NetBSD: patch-src_common_imageio__exr.hh,v 1.2 2013/05/09 15:27:02 wiz Exp $

stdc++ fixes from joerg (first, first half of third junk).

openexr-2.0 compat from http://www.darktable.org/redmine/issues/9398

--- src/common/imageio_exr.hh.orig	2013-04-03 20:13:14.000000000 +0000
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
@@ -30,8 +38,14 @@
 #include <OpenEXR/ImfChannelList.h>
 #include <OpenEXR/ImfStandardAttributes.h>
 
+#ifdef OPENEXR_IMF_INTERNAL_NAMESPACE
+#define IMF_NS OPENEXR_IMF_INTERNAL_NAMESPACE
+#else
+#define IMF_NS Imf
+#endif
+
 // this stores our exif data as a blob.
-namespace Imf
+namespace IMF_NS
 {
 class Blob
 {
@@ -50,11 +64,11 @@ public:
   }
 
   uint32_t size;
-  std::tr1::shared_ptr<uint8_t> data;
+  shared_ptr<uint8_t> data;
 };
 
 
-typedef Imf::TypedAttribute<Imf::Blob> BlobAttribute;
+typedef IMF_NS::TypedAttribute<IMF_NS::Blob> BlobAttribute;
 template <> const char *BlobAttribute::staticTypeName()
 {
   return "blob";
