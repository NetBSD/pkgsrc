$NetBSD: patch-sdk_codelite__indexer_libctags_read.c,v 1.2 2019/08/18 03:48:44 maya Exp $

Handle fpos_t on NetBSD.

--- sdk/codelite_indexer/libctags/read.c.orig	2019-05-21 17:52:21.000000000 +0300
+++ sdk/codelite_indexer/libctags/read.c
@@ -605,6 +605,9 @@ extern int readChars (char *buffer, size
 #if defined(__WXMSW__) || defined(__APPLE__) || defined(__FreeBSD__)
 	if(location < 0)
 		return 0;
+#elif defined(__NetBSD__)
+	if(location._pos < 0)
+		return 0;
 #else
 	if(location.__pos < 0)
 		return 0;
@@ -619,6 +622,8 @@ extern int readChars (char *buffer, size
 
 #if defined(__WXMSW__) || defined(__APPLE__) || defined(__FreeBSD__)
 	sizeToRead = endPos - location;
+#elif defined(__NetBSD__)
+	sizeToRead = endPos._pos - location._pos;
 #else
 	sizeToRead = endPos.__pos - location.__pos;
 #endif
