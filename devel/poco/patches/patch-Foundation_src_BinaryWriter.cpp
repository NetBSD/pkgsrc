$NetBSD: patch-Foundation_src_BinaryWriter.cpp,v 1.1 2026/07/24 12:15:52 adam Exp $

Support systems without strnlen().

--- Foundation/src/BinaryWriter.cpp.orig	2026-07-24 09:36:03.931372107 +0000
+++ Foundation/src/BinaryWriter.cpp
@@ -333,10 +333,18 @@ void BinaryWriter::writeRaw(const char*
 	_ostr.write(buffer, length);
 }
 
+#ifndef strnlen
+static std::size_t strnlen(const char* s, std::size_t maxLength)
+{
+    std::size_t i = 0;
+    while (i < maxLength && s[i] != '\0') ++i;
+    return i;
+}
+#endif
 
 void BinaryWriter::writeCString(const char* cString, std::streamsize maxLength)
 {
-	const std::size_t len = ::strnlen(cString, static_cast<std::size_t>(maxLength));
+	const std::size_t len = strnlen(cString, static_cast<std::size_t>(maxLength));
 	writeRaw(cString, len);
 	static const char zero = '\0';
 	_ostr.write(&zero, sizeof(zero));
