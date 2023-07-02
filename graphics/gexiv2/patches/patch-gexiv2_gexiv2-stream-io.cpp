$NetBSD: patch-gexiv2_gexiv2-stream-io.cpp,v 1.2 2023/07/02 15:27:51 tnn Exp $

Fix build with exiv2 0.28.0.
https://gitlab.gnome.org/GNOME/gexiv2/-/commit/06adc8fb70cb8c77c0cd364195d8251811106ef8

--- gexiv2/gexiv2-stream-io.cpp.orig	2023-05-06 08:50:03.000000000 +0000
+++ gexiv2/gexiv2-stream-io.cpp
@@ -11,15 +11,16 @@
  */
 
 #include "gexiv2-stream-io.h"
+
 #include "gexiv2-managed-stream.h"
 
+#include <config.h>
+#include <exception>
 #include <exiv2/exiv2.hpp>
 #include <gio/gio.h>
 #include <glib.h>
 #include <stdio.h>
 
-#include <exception>
-
 StreamIo::StreamIo (ManagedStreamCallbacks* callbacks)
     : cb (callbacks), memio(nullptr), is_open (FALSE), can_write(FALSE) {
     /* at least reading and seeking must be possible to read metatada */
@@ -119,7 +120,7 @@ int StreamIo::putb (Exiv2::byte data) {
     return EOF;
 }
 
-int StreamIo::seek (long offset, Position position) {
+int StreamIo::seek (int64_t offset, Position position) {
     // FIXME: handle Error
     switch (position) {
         case (beg):
@@ -138,7 +139,7 @@ int StreamIo::seek (long offset, Positio
     return 0;
 }
 
-long StreamIo::tell () const {
+StreamIo::size_type StreamIo::tell() const {
     return cb->Position (cb->handle);
 }
 
@@ -165,11 +166,14 @@ int StreamIo::close () {
 
 Exiv2::DataBuf StreamIo::read (size_type read_count) {
     Exiv2::DataBuf buffer (read_count);
-    
+#ifdef EXIV2_DATABUF_HAS_PRIVATE_PDATA
+    long read_bytes = read(buffer.data(), read_count);
+    buffer.resize(read_bytes);
+#else
     long read_bytes = read (buffer.pData_, buffer.size_);
-
     buffer.size_ = read_bytes;
-    
+#endif
+
     return buffer;
 }
 
@@ -209,12 +213,22 @@ bool StreamIo::eof () const {
     return (cb->Length (cb->handle) == cb->Position (cb->handle));
 }
 
+#if EXIV2_TEST_VERSION(0, 27, 99)
+const std::string& StreamIo::path() const noexcept {
+#else
 std::string StreamIo::path () const {
-    return "managed stream";
+#endif
+    static std::string info{"managed stream"};
+
+    return info;
 }
 
 #ifdef EXV_UNICODE_PATH
+#if EXIV2_TEST_VERSION(0, 27, 99)
+const std::wstring& StreamIo::wpath() const noexcept {
+#else
 std::wstring StreamIo::wpath() const {
+#endif
     std::string p = path();
     std::wstring w(p.length(), L' ');
     std::copy(p.begin(), p.end(), w.begin());
