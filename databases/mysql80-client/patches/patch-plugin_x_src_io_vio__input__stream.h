$NetBSD: patch-plugin_x_src_io_vio__input__stream.h,v 1.1 2025/10/15 03:52:37 jnemeth Exp $

--- plugin/x/src/io/vio_input_stream.h.orig	2025-09-26 12:55:15.014925544 +0000
+++ plugin/x/src/io/vio_input_stream.h
@@ -36,7 +36,7 @@ namespace xpl {
 
 class Vio_input_stream : public google::protobuf::io::ZeroCopyInputStream {
  public:
-  using gint64 = google::protobuf::int64;
+  using gint64 = int64_t;
 
  public:
   explicit Vio_input_stream(const std::shared_ptr<iface::Vio> &connection);
