$NetBSD: patch-gexiv2_gexiv2-stream-io.h,v 1.2 2023/07/02 15:27:51 tnn Exp $

Fix build with exiv2 0.28.0.
https://gitlab.gnome.org/GNOME/gexiv2/-/commit/06adc8fb70cb8c77c0cd364195d8251811106ef8

--- gexiv2/gexiv2-stream-io.h.orig	2023-05-06 08:50:03.000000000 +0000
+++ gexiv2/gexiv2-stream-io.h
@@ -24,10 +24,14 @@ class StreamIo : public Exiv2::BasicIo {
 public:
 #if EXIV2_TEST_VERSION(0,27,99)
     using ptr_type = Exiv2::BasicIo::UniquePtr;
-    using size_type = long;
+    using size_type = size_t;
+    using path_type = const std::string&;
+    using wpath_type = const std::wstring&;
 #else
     using ptr_type = Exiv2::BasicIo::AutoPtr;
     using size_type = long;
+    using path_type = std::string;
+    using wpath_type = std::wstring;
 #endif
 
 	StreamIo (ManagedStreamCallbacks* cb);
@@ -42,17 +46,28 @@ public:
     size_type read (Exiv2::byte* buf, size_type rcount) override;
 	int getb () override;
 	void transfer (Exiv2::BasicIo& src) override;
-	int seek (long offset, Position pos) override;
+	int seek (int64_t offset, Position pos) override;
 	Exiv2::byte* mmap (bool isWriteable = false) override;
 	int munmap () override;
-	long tell () const override;
-	size_t size () const override;
+    size_type tell() const override;
+    size_t size () const override;
 	bool isopen () const override;
 	int error () const override;
 	bool eof () const override;
-	std::string path () const override;
+#if EXIV2_TEST_VERSION(0, 27, 99)
+    void populateFakeData() override{};
+#endif
+#if EXIV2_TEST_VERSION(0, 27, 99)
+    const std::string& path() const noexcept override;
+#else
+    std::string path () const override;
+#endif
 #ifdef EXV_UNICODE_PATH
-	std::wstring wpath () const override;
+#if EXIV2_TEST_VERSION(0, 27, 99)
+    const std::wstring& wpath() const noexcept override;
+#else
+    std::wstring wpath() const override;
+#endif
 #endif
 	ptr_type temporary () const;
 
