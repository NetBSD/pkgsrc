$NetBSD: patch-src_EmbedPython_EmbeddedPython.cpp,v 1.1 2022/12/03 21:59:48 wiz Exp $

Fix build with Python 3.11.
https://github.com/Sigil-Ebook/Sigil/issues/703

--- src/EmbedPython/EmbeddedPython.cpp.orig	2022-08-31 15:13:03.000000000 +0000
+++ src/EmbedPython/EmbeddedPython.cpp
@@ -480,7 +480,7 @@ QVariant EmbeddedPython::PyObjectToQVari
 
         if (kind == PyUnicode_1BYTE_KIND) {
             // latin 1 according to PEP 393
-            res = QVariant(QString::fromLatin1(reinterpret_cast<const char *>PyUnicode_1BYTE_DATA(po), -1));
+            res = QVariant(QString::fromLatin1(reinterpret_cast<const char *>(PyUnicode_1BYTE_DATA(po), -1)));
 
         } else if (kind == PyUnicode_2BYTE_KIND) {
 #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
