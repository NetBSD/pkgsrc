$NetBSD: patch-src_OpenColorIO_OCIOZArchive.cpp,v 1.1 2023/11/07 20:29:25 nros Exp $

Fix build with minizip-ng version 4 and above
based on upstream patch:
https://github.com/AcademySoftwareFoundation/OpenColorIO/commit/bdc4cd124140f997cdec1c5d7db72b1550fe7eac

--- src/OpenColorIO/OCIOZArchive.cpp.orig	2023-01-06 02:05:59.000000000 +0000
+++ src/OpenColorIO/OCIOZArchive.cpp
@@ -225,7 +225,7 @@ void archiveConfig(std::ostream & ostrea
     std::string configStr = ss.str();
 
     // Write zip to memory stream.
-    mz_stream_mem_create(&write_mem_stream);
+    write_mem_stream = mz_stream_mem_create();
     mz_stream_mem_set_grow_size(write_mem_stream, 128 * 1024);
     mz_stream_open(write_mem_stream, NULL, MZ_OPEN_MODE_CREATE);
 
@@ -237,7 +237,7 @@ void archiveConfig(std::ostream & ostrea
     options.compress_level  = ArchiveCompressionLevels::BEST;
 
     // Create the writer handle.
-    mz_zip_writer_create(&archiver);
+    archiver = mz_zip_writer_create();
 
     // Archive options.
     // Compression method
@@ -332,7 +332,7 @@ void ExtractOCIOZArchive(const char * ar
     std::string outputDestination = pystring::os::path::normpath(destination);
 
     // Create zip reader.
-    mz_zip_reader_create(&extracter);
+    extracter = mz_zip_reader_create();
 
     MinizipNgHandlerGuard extracterGuard(extracter, false, false);
 
@@ -450,7 +450,7 @@ std::vector<uint8_t> getFileStringFromAr
     std::vector<uint8_t> buffer;
 
     // Create the reader object.
-    mz_zip_reader_create(&reader);
+    reader = mz_zip_reader_create();
 
     MinizipNgHandlerGuard extracterGuard(reader, false, true);
 
@@ -510,7 +510,7 @@ void getEntriesMappingFromArchiveFile(co
     void *reader = NULL;
 
     // Create the reader object.
-    mz_zip_reader_create(&reader);
+    reader = mz_zip_reader_create();
 
     MinizipNgHandlerGuard extracterGuard(reader, false, false);
 
@@ -630,4 +630,4 @@ void CIOPOciozArchive::buildEntries()
     getEntriesMappingFromArchiveFile(m_archiveAbsPath, m_entries);
 }
 
-} // namespace OCIO_NAMESPACE
\ No newline at end of file
+} // namespace OCIO_NAMESPACE
