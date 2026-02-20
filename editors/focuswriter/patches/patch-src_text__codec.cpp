$NetBSD: patch-src_text__codec.cpp,v 1.4 2026/02/20 08:46:41 pin Exp $

NetBSD 9 uses const in the second argument to iconv.

--- src/text_codec.cpp.orig	2026-02-19 12:34:02.786107287 +0000
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
@@ -79,7 +86,7 @@ QByteArray TextCodecIconv::fromUnicode(const QString& 
 QByteArray TextCodecIconv::fromUnicode(const QString& input)
 {
 	QByteArray in = TextCodec::fromUnicode(input);
-#ifndef __OS2__
+#if !(defined(__OS2__) || defined(__NETBSD_ICONV_CONST__))
 	// POSIX requires the source to not be const, even though it does not modify it
 	char* source = in.data();
 #else
@@ -128,7 +135,7 @@ QString TextCodecIconv::toUnicode(const QByteArray& in
 
 QString TextCodecIconv::toUnicode(const QByteArray& input)
 {
-#ifndef __OS2__
+#if !(defined(__OS2__) || defined(__NETBSD_ICONV_CONST__))
 	// POSIX requires the source to not be const, even though it does not modify it
 	char* source = const_cast<char*>(input.data());
 #else
