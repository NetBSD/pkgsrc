$NetBSD: patch-Source_Metadata_TagConversion.cpp,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/Metadata/TagConversion.cpp.orig	2018-03-25 11:30:54.000000000 +0000
+++ Source/Metadata/TagConversion.cpp
@@ -30,6 +30,11 @@
 
 #define MAX_TEXT_EXTENT	512
 
+// These were in FreeImage.h, but are moved here to avoid conflicts (see note in FreeImage.h)
+typedef int64_t INT64;
+typedef uint64_t UINT64;
+
+
 /**
 Convert a tag to a C string
 */
