$NetBSD: patch-Lib_zipfile_____init____.py,v 1.1 2025/10/11 10:14:06 wiz Exp $

https://github.com/python/cpython/commit/d11e69d6203080e3ec450446bfed0516727b85c3

--- Lib/zipfile/__init__.py.orig	2025-10-07 09:34:52.000000000 +0000
+++ Lib/zipfile/__init__.py
@@ -265,7 +265,7 @@ def is_zipfile(filename):
         else:
             with open(filename, "rb") as fp:
                 result = _check_zipfile(fp)
-    except OSError:
+    except (OSError, BadZipFile):
         pass
     return result
 
@@ -275,9 +275,6 @@ def _handle_prepended_data(endrec, debug
 
     # "concat" is zero, unless zip was concatenated to another file
     concat = endrec[_ECD_LOCATION] - size_cd - offset_cd
-    if endrec[_ECD_SIGNATURE] == stringEndArchive64:
-        # If Zip64 extension structures are present, account for them
-        concat -= (sizeEndCentDir64 + sizeEndCentDir64Locator)
 
     if debug > 2:
         inferred = concat + offset_cd
@@ -289,16 +286,15 @@ def _EndRecData64(fpin, offset, endrec):
     """
     Read the ZIP64 end-of-archive records and use that to update endrec
     """
-    try:
-        fpin.seek(offset - sizeEndCentDir64Locator, 2)
-    except OSError:
-        # If the seek fails, the file is not large enough to contain a ZIP64
+    offset -= sizeEndCentDir64Locator
+    if offset < 0:
+        # The file is not large enough to contain a ZIP64
         # end-of-archive record, so just return the end record we were given.
         return endrec
-
+    fpin.seek(offset)
     data = fpin.read(sizeEndCentDir64Locator)
     if len(data) != sizeEndCentDir64Locator:
-        return endrec
+        raise OSError("Unknown I/O error")
     sig, diskno, reloff, disks = struct.unpack(structEndArchive64Locator, data)
     if sig != stringEndArchive64Locator:
         return endrec
@@ -306,16 +302,33 @@ def _EndRecData64(fpin, offset, endrec):
     if diskno != 0 or disks > 1:
         raise BadZipFile("zipfiles that span multiple disks are not supported")
 
-    # Assume no 'zip64 extensible data'
-    fpin.seek(offset - sizeEndCentDir64Locator - sizeEndCentDir64, 2)
+    offset -= sizeEndCentDir64
+    if reloff > offset:
+        raise BadZipFile("Corrupt zip64 end of central directory locator")
+    # First, check the assumption that there is no prepended data.
+    fpin.seek(reloff)
+    extrasz = offset - reloff
     data = fpin.read(sizeEndCentDir64)
     if len(data) != sizeEndCentDir64:
-        return endrec
+        raise OSError("Unknown I/O error")
+    if not data.startswith(stringEndArchive64) and reloff != offset:
+        # Since we already have seen the Zip64 EOCD Locator, it's
+        # possible we got here because there is prepended data.
+        # Assume no 'zip64 extensible data'
+        fpin.seek(offset)
+        extrasz = 0
+        data = fpin.read(sizeEndCentDir64)
+        if len(data) != sizeEndCentDir64:
+            raise OSError("Unknown I/O error")
+    if not data.startswith(stringEndArchive64):
+        raise BadZipFile("Zip64 end of central directory record not found")
+
     sig, sz, create_version, read_version, disk_num, disk_dir, \
         dircount, dircount2, dirsize, diroffset = \
         struct.unpack(structEndArchive64, data)
-    if sig != stringEndArchive64:
-        return endrec
+    if (diroffset + dirsize != reloff or
+        sz + 12 != sizeEndCentDir64 + extrasz):
+        raise BadZipFile("Corrupt zip64 end of central directory record")
 
     # Update the original endrec using data from the ZIP64 record
     endrec[_ECD_SIGNATURE] = sig
@@ -325,6 +338,7 @@ def _EndRecData64(fpin, offset, endrec):
     endrec[_ECD_ENTRIES_TOTAL] = dircount2
     endrec[_ECD_SIZE] = dirsize
     endrec[_ECD_OFFSET] = diroffset
+    endrec[_ECD_LOCATION] = offset - extrasz
     return endrec
 
 
@@ -358,7 +372,7 @@ def _EndRecData(fpin):
         endrec.append(filesize - sizeEndCentDir)
 
         # Try to read the "Zip64 end of central directory" structure
-        return _EndRecData64(fpin, -sizeEndCentDir, endrec)
+        return _EndRecData64(fpin, filesize - sizeEndCentDir, endrec)
 
     # Either this is not a ZIP file, or it is a ZIP file with an archive
     # comment.  Search the end of the file for the "end of central directory"
@@ -382,8 +396,7 @@ def _EndRecData(fpin):
         endrec.append(maxCommentStart + start)
 
         # Try to read the "Zip64 end of central directory" structure
-        return _EndRecData64(fpin, maxCommentStart + start - filesize,
-                             endrec)
+        return _EndRecData64(fpin, maxCommentStart + start, endrec)
 
     # Unable to find a valid end of central directory structure
     return None
@@ -2142,7 +2155,7 @@ class ZipFile:
                                    " would require ZIP64 extensions")
             zip64endrec = struct.pack(
                 structEndArchive64, stringEndArchive64,
-                44, 45, 45, 0, 0, centDirCount, centDirCount,
+                sizeEndCentDir64 - 12, 45, 45, 0, 0, centDirCount, centDirCount,
                 centDirSize, centDirOffset)
             self.fp.write(zip64endrec)
 
