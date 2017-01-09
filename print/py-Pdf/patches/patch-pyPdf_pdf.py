$NetBSD: patch-pyPdf_pdf.py,v 1.2 2017/01/09 12:02:23 joerg Exp $

python-3.x compatibility.
When renaming resources, make sure that the new name is actually new.

--- pyPdf/pdf.py.orig	2010-12-04 22:49:56.000000000 +0000
+++ pyPdf/pdf.py
@@ -652,7 +652,7 @@ class PdfFileReader(object):
         if not self._override_encryption and self.isEncrypted:
             # if we don't have the encryption key:
             if not hasattr(self, '_decryption_key'):
-                raise Exception, "file has not been decrypted"
+                raise Exception("file has not been decrypted")
             # otherwise, decrypt here...
             import struct
             pack1 = struct.pack("<i", indirectReference.idnum)[:3]
@@ -704,14 +704,14 @@ class PdfFileReader(object):
         while not line:
             line = self.readNextEndLine(stream)
         if line[:5] != "%%EOF":
-            raise utils.PdfReadError, "EOF marker not found"
+            raise utils.PdfReadError("EOF marker not found")
 
         # find startxref entry - the location of the xref table
         line = self.readNextEndLine(stream)
         startxref = int(line)
         line = self.readNextEndLine(stream)
         if line[:9] != "startxref":
-            raise utils.PdfReadError, "startxref not found"
+            raise utils.PdfReadError("startxref not found")
 
         # read all cross reference tables and their trailers
         self.xref = {}
@@ -725,7 +725,7 @@ class PdfFileReader(object):
                 # standard cross-reference table
                 ref = stream.read(4)
                 if ref[:3] != "ref":
-                    raise utils.PdfReadError, "xref table read error"
+                    raise utils.PdfReadError("xref table read error")
                 readNonWhitespace(stream)
                 stream.seek(-1, 1)
                 while 1:
@@ -898,9 +898,9 @@ class PdfFileReader(object):
     def _decrypt(self, password):
         encrypt = self.trailer['/Encrypt'].getObject()
         if encrypt['/Filter'] != '/Standard':
-            raise NotImplementedError, "only Standard PDF encryption handler is available"
+            raise NotImplementedError("only Standard PDF encryption handler is available")
         if not (encrypt['/V'] in (1, 2)):
-            raise NotImplementedError, "only algorithm code 1 and 2 are supported"
+            raise NotImplementedError("only algorithm code 1 and 2 are supported")
         user_password, key = self._authenticateUserPassword(password)
         if user_password:
             self._decryption_key = key
@@ -1062,7 +1062,13 @@ class PageObject(DictionaryObject):
         renameRes = {}
         for key in page2Res.keys():
             if newRes.has_key(key) and newRes[key] != page2Res[key]:
-                newname = NameObject(key + "renamed")
+                base_newkey = key + "renamed"
+                newkey = base_newkey
+                counter = 0
+                while newRes.has_key(newkey) or page2Res.has_key(newkey):
+                    newkey = "%s%d" % (base_newkey, counter)
+                    counter = counter + 1
+                newname = NameObject(newkey)
                 renameRes[key] = newname
                 newRes[newname] = page2Res[key]
             elif not newRes.has_key(key):
