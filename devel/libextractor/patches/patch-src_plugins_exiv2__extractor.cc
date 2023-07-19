$NetBSD: patch-src_plugins_exiv2__extractor.cc,v 1.1 2023/07/19 07:35:25 wiz Exp $

Fix build with exiv2.
From Arch:
https://gitlab.archlinux.org/archlinux/packaging/packages/libextractor/-/blob/main/exiv2-0.28.patch

--- src/plugins/exiv2_extractor.cc.orig	2020-06-25 22:42:32.000000000 +0000
+++ src/plugins/exiv2_extractor.cc
@@ -90,7 +90,11 @@ virtual int close ();
  * @param rcount number of bytes to read
  * @return buffer with data read, empty buffer (!) on failure (!)
  */
+#if EXIV2_TEST_VERSION (0,28,0)
+virtual Exiv2::DataBuf read (size_t rcount);
+#else
 virtual Exiv2::DataBuf read (long rcount);
+#endif
 
 /**
  * Read up to 'rcount' bytes into 'buf'.
@@ -99,8 +103,17 @@ virtual Exiv2::DataBuf read (long rcount
  * @param rcount size of 'buf'
  * @return number of bytes read successfully, 0 on failure (!)
  */
+#if EXIV2_TEST_VERSION (0,28,0)
+virtual size_t read (Exiv2::byte *buf,
+                   size_t rcount);
+#else
 virtual long read (Exiv2::byte *buf,
                    long rcount);
+#endif
+
+#if EXIV2_TEST_VERSION (0,28,0)
+virtual void populateFakeData();
+#endif
 
 /**
  * Read a single character.
@@ -117,8 +130,13 @@ virtual int getb ();
  * @param wcount how many bytes to write
  * @return -1 (always fails)
  */
+#if EXIV2_TEST_VERSION(0,28,0)
+virtual size_t write (const Exiv2::byte *data,
+                    size_t wcount);
+#else
 virtual long write (const Exiv2::byte *data,
                     long wcount);
+#endif
 
 /**
  * Write to stream.
@@ -126,7 +144,11 @@ virtual long write (const Exiv2::byte *d
  * @param src stream to copy
  * @return -1 (always fails)
  */
+#if EXIV2_TEST_VERSION(0,28,0)
+virtual size_t write (Exiv2::BasicIo &src);
+#else
 virtual long write (Exiv2::BasicIo &src);
+#endif
 
 /**
  * Write a single byte.
@@ -172,7 +194,11 @@ virtual int munmap ();
  *
  * @return -1 on error
  */
+#if EXIV2_TEST_VERSION(0,28,0)
+virtual size_t tell (void) const;
+#else
 virtual long int tell (void) const;
+#endif
 
 /**
  * Return overall size of the file.
@@ -213,7 +239,11 @@ virtual bool eof () const;
  *
  * @throws error
  */
+#if EXIV2_TEST_VERSION(0,28,0)
+virtual const std::string& path () const noexcept;
+#else
 virtual std::string path () const;
+#endif
 
 #ifdef EXV_UNICODE_PATH
 /**
@@ -230,7 +260,11 @@ virtual std::wstring wpath () const;
  *
  * @throws error
  */
+#if EXIV2_TEST_VERSION(0,28,0)
+virtual Exiv2::BasicIo::UniquePtr temporary () const;
+#else
 virtual Exiv2::BasicIo::AutoPtr temporary () const;
+#endif
 
 };
 
@@ -266,7 +300,11 @@ ExtractorIO::close ()
  * @return buffer with data read, empty buffer (!) on failure (!)
  */
 Exiv2::DataBuf
+#if EXIV2_TEST_VERSION (0,28,0)
+ExtractorIO::read (size_t rcount)
+#else
 ExtractorIO::read (long rcount)
+#endif
 {
   void *data;
   ssize_t ret;
@@ -284,9 +322,15 @@ ExtractorIO::read (long rcount)
  * @param rcount size of 'buf'
  * @return number of bytes read successfully, 0 on failure (!)
  */
+#if EXIV2_TEST_VERSION (0,28,0)
+size_t
+ExtractorIO::read (Exiv2::byte *buf,
+                   size_t rcount)
+#else
 long
 ExtractorIO::read (Exiv2::byte *buf,
                    long rcount)
+#endif
 {
   void *data;
   ssize_t ret;
@@ -305,6 +349,12 @@ ExtractorIO::read (Exiv2::byte *buf,
   return got;
 }
 
+#if EXIV2_TEST_VERSION (0,28,0)
+void ExtractorIO::populateFakeData()
+{
+  return;
+}
+#endif
 
 /**
  * Read a single character.
@@ -319,7 +369,9 @@ ExtractorIO::getb ()
   const unsigned char *r;
 
   if (1 != ec->read (ec->cls, &data, 1))
-#if EXIV2_TEST_VERSION (0,27,0)
+#if EXIV2_TEST_VERSION(0,28,0)
+    throw Exiv2::Error (Exiv2::ErrorCode::kerDecodeLangAltQualifierFailed);
+#elif EXIV2_TEST_VERSION (0,27,0)
     throw Exiv2::BasicError<char> (Exiv2::kerDecodeLangAltQualifierFailed);
 #else
     throw Exiv2::BasicError<char> (42 /* error code */);
@@ -336,9 +388,15 @@ ExtractorIO::getb ()
  * @param wcount how many bytes to write
  * @return -1 (always fails)
  */
+#if EXIV2_TEST_VERSION(0,28,0)
+size_t
+ExtractorIO::write (const Exiv2::byte *data,
+                    size_t wcount)
+#else
 long
 ExtractorIO::write (const Exiv2::byte *data,
                     long wcount)
+#endif
 {
   return -1;
 }
@@ -350,7 +408,11 @@ ExtractorIO::write (const Exiv2::byte *d
  * @param src stream to copy
  * @return -1 (always fails)
  */
+#if EXIV2_TEST_VERSION(0,28,0)
+size_t
+#else
 long
+#endif
 ExtractorIO::write (Exiv2::BasicIo &src)
 {
   return -1;
@@ -378,7 +440,9 @@ ExtractorIO::putb (Exiv2::byte data)
 void
 ExtractorIO::transfer (Exiv2::BasicIo& src)
 {
-#if EXIV2_TEST_VERSION (0,27,0)
+#if EXIV2_TEST_VERSION(0,28,0)
+  throw Exiv2::Error (Exiv2::ErrorCode::kerDecodeLangAltQualifierFailed);
+#elif EXIV2_TEST_VERSION (0,27,0)
   throw Exiv2::BasicError<char> (Exiv2::kerDecodeLangAltQualifierFailed);
 #else
   throw Exiv2::BasicError<char> (42 /* error code */);
@@ -427,7 +491,9 @@ ExtractorIO::seek (long offset,
 Exiv2::byte *
 ExtractorIO::mmap (bool isWritable)
 {
-#if EXIV2_TEST_VERSION (0,27,0)
+#if EXIV2_TEST_VERSION (0,28,0)
+  throw Exiv2::Error (Exiv2::ErrorCode::kerDecodeLangAltQualifierFailed);
+#elif EXIV2_TEST_VERSION (0,27,0)
   throw Exiv2::BasicError<char> (Exiv2::kerDecodeLangAltQualifierFailed);
 #else
   throw Exiv2::BasicError<char> (42 /* error code */);
@@ -452,7 +518,11 @@ ExtractorIO::munmap ()
  *
  * @return -1 on error
  */
+#if EXIV2_TEST_VERSION(0,28,0)
+size_t
+#else
 long int
+#endif
 ExtractorIO::tell (void) const
 {
   return (long) ec->seek (ec->cls, 0, SEEK_CUR);
@@ -516,10 +586,17 @@ ExtractorIO::eof () const
  *
  * @throws error
  */
+#if EXIV2_TEST_VERSION (0,28,0)
+const std::string&
+ExtractorIO::path () const noexcept
+#else
 std::string
 ExtractorIO::path () const
+#endif
 {
-#if EXIV2_TEST_VERSION (0,27,0)
+#if EXIV2_TEST_VERSION (0,28,0)
+  throw Exiv2::Error (Exiv2::ErrorCode::kerDecodeLangAltQualifierFailed);
+#elif EXIV2_TEST_VERSION (0,27,0)
   throw Exiv2::BasicError<char> (Exiv2::kerDecodeLangAltQualifierFailed);
 #else
   throw Exiv2::BasicError<char> (42 /* error code */);
@@ -536,7 +613,9 @@ ExtractorIO::path () const
 std::wstring
 ExtractorIO::wpath () const
 {
-#if EXIV2_TEST_VERSION (0,27,0)
+#if EXIV2_TEST_VERSION (0,28,0)
+  throw Exiv2::Error (Exiv2::ErrorCode::kerDecodeLangAltQualifierFailed);
+#elif EXIV2_TEST_VERSION (0,27,0)
   throw Exiv2::BasicError<char> (Exiv2::kerDecodeLangAltQualifierFailed);
 #else
   throw Exiv2::BasicError<char> (42 /* error code */);
@@ -552,11 +631,17 @@ ExtractorIO::wpath () const
  *
  * @throws error
  */
+#if EXIV2_TEST_VERSION(0,28,0)
+Exiv2::BasicIo::UniquePtr
+#else
 Exiv2::BasicIo::AutoPtr
+#endif
 ExtractorIO::temporary () const
 {
   fprintf (stderr, "throwing temporary error\n");
-#if EXIV2_TEST_VERSION (0,27,0)
+#if EXIV2_TEST_VERSION(0,28,0)
+  throw Exiv2::Error (Exiv2::ErrorCode::kerDecodeLangAltQualifierFailed);
+#elif EXIV2_TEST_VERSION (0,27,0)
   throw Exiv2::BasicError<char> (Exiv2::kerDecodeLangAltQualifierFailed);
 #else
   throw Exiv2::BasicError<char> (42 /* error code */);
@@ -737,8 +822,13 @@ EXTRACTOR_exiv2_extract_method (struct E
 #if ! EXIV2_TEST_VERSION (0,24,0)
     Exiv2::LogMsg::setLevel (Exiv2::LogMsg::mute);
 #endif
+#if EXIV2_TEST_VERSION(0,28,0)
+    std::unique_ptr<Exiv2::BasicIo> eio (new ExtractorIO (ec));
+    Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open (std::move(eio));
+#else
     std::auto_ptr<Exiv2::BasicIo> eio (new ExtractorIO (ec));
     Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open (eio);
+#endif
     if (0 == image.get ())
       return;
     image->readMetadata ();
@@ -822,7 +912,11 @@ EXTRACTOR_exiv2_extract_method (struct E
       ADDXMP ("Xmp.lr.hierarchicalSubject", EXTRACTOR_METATYPE_SUBJECT);
     }
   }
+#if EXIV2_TEST_VERSION (0,28,0)
+  catch (const Exiv2::Error& e)
+#else
   catch (const Exiv2::AnyError& e)
+#endif
   {
 #if DEBUG
     std::cerr << "Caught Exiv2 exception '" << e << "'\n";
