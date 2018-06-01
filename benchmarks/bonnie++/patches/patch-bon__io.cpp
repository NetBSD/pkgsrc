$NetBSD: patch-bon__io.cpp,v 1.1 2018/06/01 10:55:52 maya Exp $

Test specifically for O_LARGEFILE, instead of tying all
of the largefile support for the LFS functions
(not available on NetBSD)

--- bon_io.cpp.orig	2009-07-03 02:26:00.000000000 +0000
+++ bon_io.cpp
@@ -291,7 +291,7 @@ int CFileOp::m_open(CPCCHAR base_name, b
   else
   {
     flags = O_RDWR;
-#ifdef _LARGEFILE64_SOURCE
+#ifdef O_LARGEFILE
     flags |= O_LARGEFILE;
 #endif
   }
