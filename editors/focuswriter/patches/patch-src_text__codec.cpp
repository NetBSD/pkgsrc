$NetBSD: patch-src_text__codec.cpp,v 1.1 2023/09/15 16:45:01 nros Exp $

* NetBSD 9 uses const in the second argument to iconv 

--- src/text_codec.cpp.orig	2023-06-27 13:32:39.000000000 +0000
+++ src/text_codec.cpp
@@ -14,6 +14,15 @@
 
 #include <errno.h>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if !(__NetBSD_Prereq__(9,99,18))
+#define __NETBSD_ICONV_CONST__ 1
+#endif
+#endif
+
+
+
 //-----------------------------------------------------------------------------
 
 namespace
@@ -79,7 +88,7 @@ TextCodecIconv::~TextCodecIconv()
 QByteArray TextCodecIconv::fromUnicode(const QString& input)
 {
 	QByteArray in = TextCodec::fromUnicode(input);
-#ifndef __OS2__
+#if !(defined(__OS2__) || defined(__NETBSD_ICONV_CONST__))
 	// POSIX requires the source to not be const, even though it does not modify it
 	char* source = in.data();
 #else
@@ -128,7 +137,7 @@ QByteArray TextCodecIconv::fromUnicode(c
 
 QString TextCodecIconv::toUnicode(const QByteArray& input)
 {
-#ifndef __OS2__
+#if !(defined(__OS2__) || defined(__NETBSD_ICONV_CONST__))
 	// POSIX requires the source to not be const, even though it does not modify it
 	char* source = const_cast<char*>(input.data());
 #else
