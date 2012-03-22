$NetBSD: patch-src_libkbibtexio_iconvlatex.cpp,v 1.1 2012/03/22 07:06:25 markd Exp $

--- src/libkbibtexio/iconvlatex.cpp.orig	2011-11-20 20:36:55.000000000 +0000
+++ src/libkbibtexio/iconvlatex.cpp
@@ -57,7 +57,7 @@ IConvLaTeX::~IConvLaTeX()
 QByteArray IConvLaTeX::encode(const QString &input)
 {
     QByteArray inputByteArray = input.toUtf8();
-#ifdef Q_WS_WIN
+#if defined(Q_WS_WIN) || defined(Q_OS_NETBSD) 
     /// iconv on Windows likes to have it as const char *
     const char *inputBuffer = inputByteArray.data();
 #else
