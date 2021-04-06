$NetBSD: patch-pyPdf_generic.py,v 1.2 2021/04/06 18:57:10 joerg Exp $

python-3.x compatibility.

--- pyPdf/generic.py.orig	2010-12-04 22:49:56.000000000 +0000
+++ pyPdf/generic.py
@@ -99,7 +99,7 @@ class NullObject(PdfObject):
     def readFromStream(stream):
         nulltxt = stream.read(4)
         if nulltxt != "null":
-            raise utils.PdfReadError, "error reading null object"
+            raise utils.PdfReadError("error reading null object")
         return NullObject()
     readFromStream = staticmethod(readFromStream)
 
@@ -137,7 +137,7 @@ class ArrayObject(list, PdfObject):
         arr = ArrayObject()
         tmp = stream.read(1)
         if tmp != "[":
-            raise utils.PdfReadError, "error reading array"
+            raise utils.PdfReadError("error reading array")
         while True:
             # skip leading whitespace
             tok = stream.read(1)
@@ -245,20 +245,22 @@ def createStringObject(string):
         return TextStringObject(string)
     elif isinstance(string, str):
         if string.startswith(codecs.BOM_UTF16_BE):
-            retval = TextStringObject(string.decode("utf-16"))
-            retval.autodetect_utf16 = True
-            return retval
-        else:
-            # This is probably a big performance hit here, but we need to
-            # convert string objects into the text/unicode-aware version if
-            # possible... and the only way to check if that's possible is
-            # to try.  Some strings are strings, some are just byte arrays.
             try:
-                retval = TextStringObject(decode_pdfdocencoding(string))
-                retval.autodetect_pdfdocencoding = True
+                retval = TextStringObject(string.decode("utf-16"))
+                retval.autodetect_utf16 = True
                 return retval
             except UnicodeDecodeError:
-                return ByteStringObject(string)
+                pass
+        # This is probably a big performance hit here, but we need to
+        # convert string objects into the text/unicode-aware version if
+        # possible... and the only way to check if that's possible is
+        # to try.  Some strings are strings, some are just byte arrays.
+        try:
+            retval = TextStringObject(decode_pdfdocencoding(string))
+            retval.autodetect_pdfdocencoding = True
+            return retval
+        except UnicodeDecodeError:
+            return ByteStringObject(string)
     else:
         raise TypeError("createStringObject should have str or unicode arg")
 
@@ -425,7 +427,7 @@ class NameObject(str, PdfObject):
     def readFromStream(stream):
         name = stream.read(1)
         if name != "/":
-            raise utils.PdfReadError, "name read error"
+            raise utils.PdfReadError("name read error")
         while True:
             tok = stream.read(1)
             if tok.isspace() or tok in NameObject.delimiterCharacters:
@@ -517,7 +519,7 @@ class DictionaryObject(dict, PdfObject):
     def readFromStream(stream, pdf):
         tmp = stream.read(2)
         if tmp != "<<":
-            raise utils.PdfReadError, "dictionary read error"
+            raise utils.PdfReadError("dictionary read error")
         data = {}
         while True:
             tok = readNonWhitespace(stream)
@@ -531,7 +533,7 @@ class DictionaryObject(dict, PdfObject):
             value = readObject(stream, pdf)
             if data.has_key(key):
                 # multiple definitions of key not permitted
-                raise utils.PdfReadError, "multiple definitions in dictionary"
+                raise utils.PdfReadError("multiple definitions in dictionary")
             data[key] = value
         pos = stream.tell()
         s = readNonWhitespace(stream)
@@ -570,7 +572,7 @@ class DictionaryObject(dict, PdfObject):
                     data["__streamdata__"] = data["__streamdata__"][:-1]
                 else:
                     stream.seek(pos, 0)
-                    raise utils.PdfReadError, "Unable to find 'endstream' marker after stream."
+                    raise utils.PdfReadError("Unable to find 'endstream' marker after stream.")
         else:
             stream.seek(pos, 0)
         if data.has_key("__streamdata__"):
@@ -655,7 +657,7 @@ class EncodedStreamObject(StreamObject):
             return decoded._data
 
     def setData(self, data):
-        raise utils.PdfReadError, "Creating EncodedStreamObject is not currently supported"
+        raise utils.PdfReadError("Creating EncodedStreamObject is not currently supported")
 
 
 class RectangleObject(ArrayObject):
