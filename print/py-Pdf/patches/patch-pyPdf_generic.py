$NetBSD: patch-pyPdf_generic.py,v 1.1 2014/01/23 14:38:42 wiz Exp $

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
@@ -425,7 +425,7 @@ class NameObject(str, PdfObject):
     def readFromStream(stream):
         name = stream.read(1)
         if name != "/":
-            raise utils.PdfReadError, "name read error"
+            raise utils.PdfReadError("name read error")
         while True:
             tok = stream.read(1)
             if tok.isspace() or tok in NameObject.delimiterCharacters:
@@ -517,7 +517,7 @@ class DictionaryObject(dict, PdfObject):
     def readFromStream(stream, pdf):
         tmp = stream.read(2)
         if tmp != "<<":
-            raise utils.PdfReadError, "dictionary read error"
+            raise utils.PdfReadError("dictionary read error")
         data = {}
         while True:
             tok = readNonWhitespace(stream)
@@ -531,7 +531,7 @@ class DictionaryObject(dict, PdfObject):
             value = readObject(stream, pdf)
             if data.has_key(key):
                 # multiple definitions of key not permitted
-                raise utils.PdfReadError, "multiple definitions in dictionary"
+                raise utils.PdfReadError("multiple definitions in dictionary")
             data[key] = value
         pos = stream.tell()
         s = readNonWhitespace(stream)
@@ -570,7 +570,7 @@ class DictionaryObject(dict, PdfObject):
                     data["__streamdata__"] = data["__streamdata__"][:-1]
                 else:
                     stream.seek(pos, 0)
-                    raise utils.PdfReadError, "Unable to find 'endstream' marker after stream."
+                    raise utils.PdfReadError("Unable to find 'endstream' marker after stream.")
         else:
             stream.seek(pos, 0)
         if data.has_key("__streamdata__"):
@@ -655,7 +655,7 @@ class EncodedStreamObject(StreamObject):
             return decoded._data
 
     def setData(self, data):
-        raise utils.PdfReadError, "Creating EncodedStreamObject is not currently supported"
+        raise utils.PdfReadError("Creating EncodedStreamObject is not currently supported")
 
 
 class RectangleObject(ArrayObject):
