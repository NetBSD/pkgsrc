$NetBSD: patch-gexiv2_gexiv2-metadata.cpp,v 1.2 2023/07/02 15:27:51 tnn Exp $

Fix build with exiv2 0.28.0.
https://gitlab.gnome.org/GNOME/gexiv2/-/commit/06adc8fb70cb8c77c0cd364195d8251811106ef8

--- gexiv2/gexiv2-metadata.cpp.orig	2023-05-06 08:50:03.000000000 +0000
+++ gexiv2/gexiv2-metadata.cpp
@@ -9,19 +9,22 @@
  */
 
 #include "gexiv2-metadata.h"
-#include "gexiv2-metadata-private.h"
-#include "gexiv2-stream-io.h"
+
+#include "gexiv2-log-private.h"
+#include "gexiv2-log.h"
 #include "gexiv2-managed-stream.h"
-#include "gexiv2-preview-properties.h"
-#include "gexiv2-preview-properties-private.h"
-#include "gexiv2-preview-image.h"
+#include "gexiv2-metadata-private.h"
 #include "gexiv2-preview-image-private.h"
-#include "gexiv2-log.h"
-#include "gexiv2-log-private.h"
-#include <string>
+#include "gexiv2-preview-image.h"
+#include "gexiv2-preview-properties-private.h"
+#include "gexiv2-preview-properties.h"
+#include "gexiv2-stream-io.h"
+
 #include <cmath>
-#include <glib-object.h>
+#include <config.h>
 #include <gio/gio.h>
+#include <glib-object.h>
+#include <string>
 
 #ifdef G_OS_WIN32
 #include <glib/gwin32.h>
@@ -46,7 +49,7 @@ public:
         , _eof{false}
         {}
 #if EXIV2_TEST_VERSION(0,27,99)
-    using size_type = long;
+    using size_type = size_t;
 #else
     using size_type = long;
 #endif
@@ -54,7 +57,7 @@ public:
     size_type _size;
 
     ~GioIo() { g_clear_object (&_is); g_clear_error (&_error); _seekable = NULL;}
-#if defined(_MSC_VER)
+#if defined(_MSC_VER) || EXIV2_TEST_VERSION(0,27,99)
     typedef int64_t seek_offset_t;
 #else
     typedef long seek_offset_t;
@@ -66,6 +69,9 @@ public:
     using ptr_type = Exiv2::BasicIo::AutoPtr;
 #endif
 
+#if EXIV2_TEST_VERSION(0, 27, 99)
+    void populateFakeData() override{};
+#endif
     int open() override {
         if (_seekable == nullptr)
             return 0;
@@ -91,9 +97,17 @@ public:
     Exiv2::DataBuf read(size_type rcount) override {
         Exiv2::DataBuf b{rcount};
 
+#ifdef EXIV2_DATABUF_HAS_PRIVATE_PDATA
+        auto bytes_read = this->read(b.data(), rcount);
+#else
         auto bytes_read = this->read(b.pData_, rcount);
+#endif
         if (bytes_read > 0 && bytes_read != rcount) {
+#ifdef EXIV2_DATABUF_HAS_PRIVATE_PDATA
+            b = Exiv2::DataBuf{b};
+#else
             b.reset({b.pData_, bytes_read});
+#endif
         }
 
         return b;
@@ -188,7 +202,7 @@ public:
 
     int munmap() override { return 0; }
 
-    long tell() const override {
+    size_type tell() const override {
         if (_seekable != nullptr && g_seekable_can_seek (_seekable)) {
             return static_cast<long>(g_seekable_tell (_seekable));
         } else {
@@ -204,10 +218,21 @@ public:
 
     bool eof() const override { return _eof; }
 
+#if EXIV2_TEST_VERSION(0, 27, 99)
+    const std::string& path() const noexcept override {
+        static std::string info{"GIO Wrapper"};
+        return info;
+    }
+#else
     std::string path() const override { return "GIO Wrapper"; }
+#endif
 
 #ifdef EXV_UNICODE_PATH
+#ifdef EXIV2_TEST_VERSION(0, 27, 99)
+    const std::wstring& wpath() const noexcept override {
+#else
     std::wstring wpath() const override {
+#endif
         std::string p = path();
         std::wstring w(p.length(), L' ');
         std::copy(p.begin(), p.end(), w.begin());
@@ -395,7 +420,7 @@ static void gexiv2_metadata_init_interna
         if (priv->preview_manager)
             delete priv->preview_manager;
 
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 }
 
@@ -416,7 +441,7 @@ static gboolean gexiv2_metadata_open_int
 
         return !(error && *error);
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return FALSE;
@@ -476,11 +501,11 @@ gboolean gexiv2_metadata_open_path(GExiv
 
         return gexiv2_metadata_open_internal (self, error);
     } catch (Exiv2::Error &e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal (error, g_quark_from_string ("GExiv2"), static_cast<int>(e.code()), e.what ());
     }
 #ifdef EXV_UNICODE_PATH
     catch (Exiv2::WError &e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal (error, g_quark_from_string ("GExiv2"), static_cast<int>(e.code()), e.what ());
     }
 #endif
 
@@ -503,7 +528,7 @@ gboolean gexiv2_metadata_open_buf(GExiv2
 
 gboolean gexiv2_metadata_open_stream (GExiv2Metadata *self, ManagedStreamCallbacks* cb, GError **error) {
     g_return_val_if_fail (GEXIV2_IS_METADATA (self), FALSE);
-    
+
     try {
         StreamIo::ptr_type stream_ptr{new StreamIo (cb)};
 #if EXIV2_TEST_VERSION(0,27,99)
@@ -514,7 +539,7 @@ gboolean gexiv2_metadata_open_stream (GE
         
         return gexiv2_metadata_open_internal (self, error);
     } catch (Exiv2::Error &e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal (error, g_quark_from_string ("GExiv2"), static_cast<int>(e.code()), e.what ());
     }
     
     return FALSE;
@@ -533,7 +558,7 @@ gboolean gexiv2_metadata_from_stream(GEx
 
         return gexiv2_metadata_open_internal (self, error);
     } catch (Exiv2::Error &e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 
     return FALSE;
@@ -584,7 +609,7 @@ gboolean gexiv2_metadata_from_app1_segme
         return TRUE;
     } catch (Exiv2::Error &e) {
         delete self->priv->image.release();
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     return FALSE;
 }
@@ -653,7 +678,7 @@ static gboolean gexiv2_metadata_save_int
 
         return TRUE;
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
     return FALSE;
 }
@@ -675,11 +700,11 @@ gboolean gexiv2_metadata_save_external (
                                              Exiv2::ImageFactory::create(Exiv2::ImageType::xmp, local_path),
                                              error);
     } catch (Exiv2::Error &e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal (error, g_quark_from_string ("GExiv2"), static_cast<int>(e.code()), e.what ());
     }
 #ifdef EXV_UNICODE_PATH
     catch (Exiv2::WError &e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal (error, g_quark_from_string ("GExiv2"), static_cast<int>(e.code()), e.what ());
     }
 #endif
 
@@ -701,11 +726,11 @@ gboolean gexiv2_metadata_save_file (GExi
 
         return gexiv2_metadata_save_internal(self, Exiv2::ImageFactory::open(local_path), error);
     } catch (Exiv2::Error &e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal (error, g_quark_from_string ("GExiv2"), static_cast<int>(e.code()), e.what ());
     }
 #ifdef EXV_UNICODE_PATH
     catch (Exiv2::WError &e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal (error, g_quark_from_string ("GExiv2"), static_cast<int>(e.code()), e.what ());
     }
 #endif
     
@@ -713,8 +738,8 @@ gboolean gexiv2_metadata_save_file (GExi
 }
 
 gboolean gexiv2_metadata_save_stream (GExiv2Metadata *self, ManagedStreamCallbacks* cb, GError **error) {
-    g_return_val_if_fail (GEXIV2_IS_METADATA (self), FALSE);
-    
+    g_return_val_if_fail(GEXIV2_IS_METADATA(self), FALSE);
+
     try {
         StreamIo::ptr_type stream_ptr{new StreamIo (cb)};
         
@@ -724,7 +749,7 @@ gboolean gexiv2_metadata_save_stream (GE
         return gexiv2_metadata_save_internal (self, Exiv2::ImageFactory::open (stream_ptr), error);
 #endif
     } catch (Exiv2::Error &e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal (error, g_quark_from_string ("GExiv2"), static_cast<int>(e.code()), e.what ());
     }
     
     return FALSE;
@@ -761,7 +786,7 @@ gboolean gexiv2_metadata_try_has_tag(GEx
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return FALSE;
 }
@@ -797,7 +822,7 @@ gboolean gexiv2_metadata_try_clear_tag(G
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return FALSE;
 }
@@ -954,7 +979,7 @@ void gexiv2_metadata_try_set_orientation
         gexiv2_metadata_clear_exif_tag(self, "Exif.MinoltaCs7D.Rotation");
         gexiv2_metadata_clear_exif_tag(self, "Exif.MinoltaCs5D.Rotation");
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 }
 
@@ -1075,7 +1100,7 @@ void gexiv2_metadata_try_set_metadata_pi
         xmp_data["Xmp.tiff.ImageWidth"] = static_cast<uint32_t>(width);
         xmp_data["Xmp.exif.PixelXDimension"] = static_cast<uint32_t>(width);
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 }
 
@@ -1104,7 +1129,7 @@ void gexiv2_metadata_try_set_metadata_pi
         xmp_data["Xmp.tiff.ImageLength"] = static_cast<uint32_t>(height);
         xmp_data["Xmp.exif.PixelYDimension"] = static_cast<uint32_t>(height);
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 }
 
@@ -1226,7 +1251,7 @@ void gexiv2_metadata_try_set_comment(GEx
         /* Do not need to write to acdsee properties, just read from them */
         // xmp_data ["Xmp.acdsee.notes"] = comment;
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 }
 
@@ -1273,7 +1298,7 @@ gchar* gexiv2_metadata_try_get_tag_strin
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return nullptr;
 }
@@ -1295,7 +1320,7 @@ gboolean gexiv2_metadata_try_set_tag_str
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return FALSE;
 }
@@ -1353,7 +1378,7 @@ gchar* gexiv2_metadata_try_get_tag_inter
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return nullptr;
 }
@@ -1393,7 +1418,7 @@ gchar** gexiv2_metadata_try_get_tag_mult
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return nullptr;
 }
@@ -1416,7 +1441,7 @@ gboolean gexiv2_metadata_try_set_tag_mul
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return FALSE;
 }
@@ -1459,7 +1484,7 @@ gchar** gexiv2_metadata_get_tag_multiple
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(&error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(&error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     g_warning("%s", error->message);
     g_clear_error(&error);
 
@@ -1499,7 +1524,7 @@ glong gexiv2_metadata_try_get_tag_long(G
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return 0;
 }
@@ -1536,7 +1561,7 @@ gboolean gexiv2_metadata_try_set_tag_lon
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return FALSE;
 }
@@ -1691,6 +1716,12 @@ gboolean gexiv2_metadata_get_exif_thumbn
     g_return_val_if_fail(self->priv->image.get() != nullptr, FALSE);
 
     Exiv2::ExifThumb thumb = Exiv2::ExifThumb(self->priv->image->exifData());
+#ifdef EXIV2_DATABUF_HAS_PRIVATE_PDATA
+    auto buf = thumb.copy();
+    *buffer = reinterpret_cast<guint8*>(g_malloc(buf.size()));
+    std::copy(buf.begin(), buf.end(), *buffer);
+    *size = buf.size();
+#else
     Exiv2::DataBuf data = thumb.copy();
     if (data.pData_ == nullptr)
         return FALSE;
@@ -1698,6 +1729,7 @@ gboolean gexiv2_metadata_get_exif_thumbn
     *buffer = (guint8*) g_malloc(data.size_);
     memcpy(*buffer, data.pData_, data.size_);
     *size = data.size_;
+#endif
 
     return TRUE;
 }
@@ -1713,7 +1745,7 @@ gboolean gexiv2_metadata_set_exif_thumbn
         
         return TRUE;
     } catch (Exiv2::Error &e) {
-        g_set_error_literal (error, g_quark_from_string ("GExiv2"), e.code (), e.what ());
+        g_set_error_literal (error, g_quark_from_string ("GExiv2"), static_cast<int>(e.code()), e.what ());
     }
     
     return FALSE;
@@ -1745,7 +1777,7 @@ void gexiv2_metadata_try_set_exif_thumbn
         Exiv2::ExifThumb thumb = Exiv2::ExifThumb(self->priv->image->exifData());
         thumb.setJpegThumbnail(buffer, size);
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 }
 
@@ -1769,7 +1801,7 @@ void gexiv2_metadata_try_erase_exif_thum
         Exiv2::ExifThumb thumb = Exiv2::ExifThumb(self->priv->image->exifData());
         thumb.erase();
     } catch (Exiv2::Error& e) {
-        g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+        g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
     }
 }
 
@@ -1788,7 +1820,7 @@ const gchar* gexiv2_metadata_try_get_tag
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return nullptr;
 }
@@ -1824,7 +1856,7 @@ const gchar* gexiv2_metadata_try_get_tag
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return nullptr;
 }
@@ -1860,7 +1892,7 @@ const gchar* gexiv2_metadata_try_get_tag
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return nullptr;
 }
@@ -1899,7 +1931,7 @@ gboolean gexiv2_metadata_try_tag_support
 
     // Invalid tag (Family name)
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return FALSE;
 }
@@ -1921,7 +1953,7 @@ GBytes* gexiv2_metadata_try_get_tag_raw(
 
     // Invalid "familyName"
     Exiv2::Error e(Exiv2::ErrorCode::kerInvalidKey, tag);
-    g_set_error_literal(error, g_quark_from_string("GExiv2"), e.code(), e.what());
+    g_set_error_literal(error, g_quark_from_string("GExiv2"), static_cast<int>(e.code()), e.what());
 
     return nullptr;
 }
