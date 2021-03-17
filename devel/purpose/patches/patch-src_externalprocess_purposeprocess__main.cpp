$NetBSD: patch-src_externalprocess_purposeprocess__main.cpp,v 1.1 2021/03/17 22:33:38 markd Exp $

Seems 5.15.2 still does it the old way

--- src/externalprocess/purposeprocess_main.cpp.orig	2020-05-02 22:25:20.000000000 +0000
+++ src/externalprocess/purposeprocess_main.cpp
@@ -90,7 +90,7 @@ public:
 
 private Q_SLOTS:
     void error() {
-#if (QT_VERSION <= QT_VERSION_CHECK(5, 15, 0))
+#if (QT_VERSION <= QT_VERSION_CHECK(5, 15, 2))
         const auto socketError = m_socket.error();
 #else
         const auto socketError = m_socket.socketError();
