$NetBSD: patch-src_text__codec.cpp,v 1.3 2024/05/03 09:16:52 pin Exp $

NetBSD 9 uses const in the second argument to iconv.

--- src/text_codec.cpp.orig	2024-05-03 08:38:17.190099116 +0000
+++ src/text_codec.cpp
@@ -14,6 +14,13 @@
 
 #include <errno.h>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if !(__NetBSD_Prereq__(9,99,18))
+#define __NETBSD_ICONV_CONST__ 1
+#endif
+#endif
+
 //-----------------------------------------------------------------------------
 
 namespace
@@ -79,7 +86,7 @@ TextCodecIconv::~TextCodecIconv()
 QByteArray TextCodecIconv::fromUnicode(const QString& input)
 {
 	QByteArray in = TextCodec::fromUnicode(input);
-#ifndef __OS2__
+#if !(defined(__OS2__) || defined(__NETBSD_ICONV_CONST__))
 	// POSIX requires the source to not be const, even though it does not modify it
 	char* source = in.data();
 #else
@@ -128,7 +135,7 @@ QByteArray TextCodecIconv::fromUnicode(c
 
 QString TextCodecIconv::toUnicode(const QByteArray& input)
 {
-#ifndef __OS2__
+#if !(defined(__OS2__) || defined(__NETBSD_ICONV_CONST__))
 	// POSIX requires the source to not be const, even though it does not modify it
 	char* source = const_cast<char*>(input.data());
 #else
