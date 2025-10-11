$NetBSD: patch-Lib_test_test__zipfile_test__core.py,v 1.1 2025/10/11 19:07:06 wiz Exp $

https://github.com/python/cpython/commit/333d4a6f4967d3ace91492a39ededbcf3faa76a6

--- Lib/test/test_zipfile/test_core.py.orig	2025-10-07 12:01:51.000000000 +0000
+++ Lib/test/test_zipfile/test_core.py
@@ -884,6 +884,8 @@ class StoredTestZip64InSmallFiles(Abstra
         self, file_size_64_set=False, file_size_extra=False,
         compress_size_64_set=False, compress_size_extra=False,
         header_offset_64_set=False, header_offset_extra=False,
+        extensible_data=b'',
+        end_of_central_dir_size=None, offset_to_end_of_central_dir=None,
     ):
         """Generate bytes sequence for a zip with (incomplete) zip64 data.
 
@@ -937,6 +939,12 @@ class StoredTestZip64InSmallFiles(Abstra
 
         central_dir_size = struct.pack('<Q', 58 + 8 * len(central_zip64_fields))
         offset_to_central_dir = struct.pack('<Q', 50 + 8 * len(local_zip64_fields))
+        if end_of_central_dir_size is None:
+            end_of_central_dir_size = 44 + len(extensible_data)
+        if offset_to_end_of_central_dir is None:
+            offset_to_end_of_central_dir = (108
+                                            + 8 * len(local_zip64_fields)
+                                            + 8 * len(central_zip64_fields))
 
         local_extra_length = struct.pack("<H", 4 + 8 * len(local_zip64_fields))
         central_extra_length = struct.pack("<H", 4 + 8 * len(central_zip64_fields))
@@ -965,14 +973,17 @@ class StoredTestZip64InSmallFiles(Abstra
             + filename
             + central_extra
             # Zip64 end of central directory
-            + b"PK\x06\x06,\x00\x00\x00\x00\x00\x00\x00-\x00-"
-            + b"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00"
+            + b"PK\x06\x06"
+            + struct.pack('<Q', end_of_central_dir_size)
+            + b"-\x00-\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00"
             + b"\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00"
             + central_dir_size
             + offset_to_central_dir
+            + extensible_data
             # Zip64 end of central directory locator
-            + b"PK\x06\x07\x00\x00\x00\x00l\x00\x00\x00\x00\x00\x00\x00\x01"
-            + b"\x00\x00\x00"
+            + b"PK\x06\x07\x00\x00\x00\x00"
+            + struct.pack('<Q', offset_to_end_of_central_dir)
+            + b"\x01\x00\x00\x00"
             # end of central directory
             + b"PK\x05\x06\x00\x00\x00\x00\x01\x00\x01\x00:\x00\x00\x002\x00"
             + b"\x00\x00\x00\x00"
@@ -1003,6 +1014,7 @@ class StoredTestZip64InSmallFiles(Abstra
         with self.assertRaises(zipfile.BadZipFile) as e:
             zipfile.ZipFile(io.BytesIO(missing_file_size_extra))
         self.assertIn('file size', str(e.exception).lower())
+        self.assertTrue(zipfile.is_zipfile(io.BytesIO(missing_file_size_extra)))
 
         # zip64 file size present, zip64 compress size present, one field in
         # extra, expecting two, equals missing compress size.
@@ -1014,6 +1026,7 @@ class StoredTestZip64InSmallFiles(Abstra
         with self.assertRaises(zipfile.BadZipFile) as e:
             zipfile.ZipFile(io.BytesIO(missing_compress_size_extra))
         self.assertIn('compress size', str(e.exception).lower())
+        self.assertTrue(zipfile.is_zipfile(io.BytesIO(missing_compress_size_extra)))
 
         # zip64 compress size present, no fields in extra, expecting one,
         # equals missing compress size.
@@ -1023,6 +1036,7 @@ class StoredTestZip64InSmallFiles(Abstra
         with self.assertRaises(zipfile.BadZipFile) as e:
             zipfile.ZipFile(io.BytesIO(missing_compress_size_extra))
         self.assertIn('compress size', str(e.exception).lower())
+        self.assertTrue(zipfile.is_zipfile(io.BytesIO(missing_compress_size_extra)))
 
         # zip64 file size present, zip64 compress size present, zip64 header
         # offset present, two fields in extra, expecting three, equals missing
@@ -1037,6 +1051,7 @@ class StoredTestZip64InSmallFiles(Abstra
         with self.assertRaises(zipfile.BadZipFile) as e:
             zipfile.ZipFile(io.BytesIO(missing_header_offset_extra))
         self.assertIn('header offset', str(e.exception).lower())
+        self.assertTrue(zipfile.is_zipfile(io.BytesIO(missing_header_offset_extra)))
 
         # zip64 compress size present, zip64 header offset present, one field
         # in extra, expecting two, equals missing header offset
@@ -1049,6 +1064,7 @@ class StoredTestZip64InSmallFiles(Abstra
         with self.assertRaises(zipfile.BadZipFile) as e:
             zipfile.ZipFile(io.BytesIO(missing_header_offset_extra))
         self.assertIn('header offset', str(e.exception).lower())
+        self.assertTrue(zipfile.is_zipfile(io.BytesIO(missing_header_offset_extra)))
 
         # zip64 file size present, zip64 header offset present, one field in
         # extra, expecting two, equals missing header offset
@@ -1061,6 +1077,7 @@ class StoredTestZip64InSmallFiles(Abstra
         with self.assertRaises(zipfile.BadZipFile) as e:
             zipfile.ZipFile(io.BytesIO(missing_header_offset_extra))
         self.assertIn('header offset', str(e.exception).lower())
+        self.assertTrue(zipfile.is_zipfile(io.BytesIO(missing_header_offset_extra)))
 
         # zip64 header offset present, no fields in extra, expecting one,
         # equals missing header offset
@@ -1072,6 +1089,63 @@ class StoredTestZip64InSmallFiles(Abstra
         with self.assertRaises(zipfile.BadZipFile) as e:
             zipfile.ZipFile(io.BytesIO(missing_header_offset_extra))
         self.assertIn('header offset', str(e.exception).lower())
+        self.assertTrue(zipfile.is_zipfile(io.BytesIO(missing_header_offset_extra)))
+
+    def test_bad_zip64_end_of_central_dir(self):
+        zipdata = self.make_zip64_file(end_of_central_dir_size=0)
+        with self.assertRaisesRegex(zipfile.BadZipFile, 'Corrupt.*record'):
+            zipfile.ZipFile(io.BytesIO(zipdata))
+        self.assertFalse(zipfile.is_zipfile(io.BytesIO(zipdata)))
+
+        zipdata = self.make_zip64_file(end_of_central_dir_size=100)
+        with self.assertRaisesRegex(zipfile.BadZipFile, 'Corrupt.*record'):
+            zipfile.ZipFile(io.BytesIO(zipdata))
+        self.assertFalse(zipfile.is_zipfile(io.BytesIO(zipdata)))
+
+        zipdata = self.make_zip64_file(offset_to_end_of_central_dir=0)
+        with self.assertRaisesRegex(zipfile.BadZipFile, 'Corrupt.*record'):
+            zipfile.ZipFile(io.BytesIO(zipdata))
+        self.assertFalse(zipfile.is_zipfile(io.BytesIO(zipdata)))
+
+        zipdata = self.make_zip64_file(offset_to_end_of_central_dir=1000)
+        with self.assertRaisesRegex(zipfile.BadZipFile, 'Corrupt.*locator'):
+            zipfile.ZipFile(io.BytesIO(zipdata))
+        self.assertFalse(zipfile.is_zipfile(io.BytesIO(zipdata)))
+
+    def test_zip64_end_of_central_dir_record_not_found(self):
+        zipdata = self.make_zip64_file()
+        zipdata = zipdata.replace(b"PK\x06\x06", b'\x00'*4)
+        with self.assertRaisesRegex(zipfile.BadZipFile, 'record not found'):
+            zipfile.ZipFile(io.BytesIO(zipdata))
+        self.assertFalse(zipfile.is_zipfile(io.BytesIO(zipdata)))
+
+        zipdata = self.make_zip64_file(
+            extensible_data=b'\xca\xfe\x04\x00\x00\x00data')
+        zipdata = zipdata.replace(b"PK\x06\x06", b'\x00'*4)
+        with self.assertRaisesRegex(zipfile.BadZipFile, 'record not found'):
+            zipfile.ZipFile(io.BytesIO(zipdata))
+        self.assertFalse(zipfile.is_zipfile(io.BytesIO(zipdata)))
+
+    def test_zip64_extensible_data(self):
+        # These values are what is set in the make_zip64_file method.
+        expected_file_size = 8
+        expected_compress_size = 8
+        expected_header_offset = 0
+        expected_content = b"test1234"
+
+        zipdata = self.make_zip64_file(
+            extensible_data=b'\xca\xfe\x04\x00\x00\x00data')
+        with zipfile.ZipFile(io.BytesIO(zipdata)) as zf:
+            zinfo = zf.infolist()[0]
+            self.assertEqual(zinfo.file_size, expected_file_size)
+            self.assertEqual(zinfo.compress_size, expected_compress_size)
+            self.assertEqual(zinfo.header_offset, expected_header_offset)
+            self.assertEqual(zf.read(zinfo), expected_content)
+        self.assertTrue(zipfile.is_zipfile(io.BytesIO(zipdata)))
+
+        with self.assertRaisesRegex(zipfile.BadZipFile, 'record not found'):
+            zipfile.ZipFile(io.BytesIO(b'prepended' + zipdata))
+        self.assertFalse(zipfile.is_zipfile(io.BytesIO(b'prepended' + zipdata)))
 
     def test_generated_valid_zip64_extra(self):
         # These values are what is set in the make_zip64_file method.
