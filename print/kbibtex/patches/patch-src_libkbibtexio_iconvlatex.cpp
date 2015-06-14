$NetBSD: patch-src_libkbibtexio_iconvlatex.cpp,v 1.2 2015/06/14 12:50:00 markd Exp $

--- src/libkbibtexio/iconvlatex.cpp.orig	2014-05-19 18:28:50.000000000 +0000
+++ src/libkbibtexio/iconvlatex.cpp
@@ -62,7 +62,7 @@ QByteArray IConvLaTeX::encode(const QStr
     /// Limit the size of the output buffer
     /// by making an educated guess of its maximum size
     size_t maxOutputByteArraySize = inputByteArray.size() * 4 + 1024;
-#ifdef Q_WS_WIN
+#if defined(Q_WS_WIN) || defined(Q_OS_NETBSD)
     /// iconv on Windows likes to have it as const char *
     const char *inputBuffer = inputByteArray.data();
 #else
