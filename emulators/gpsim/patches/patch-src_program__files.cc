$NetBSD: patch-src_program__files.cc,v 1.2 2013/06/11 12:58:42 ryoon Exp $

Fix namespace.

--- src/program_files.cc.orig	2007-02-11 20:49:21.000000000 +0000
+++ src/program_files.cc
@@ -139,7 +139,7 @@ ProgramFileBuf::int_type ProgramFileBuf:
   if (numPutback > 4) {
     numPutback = 4;
   }
-  std::memcpy (m_Buffer+(4-numPutback), gptr() - numPutback, numPutback);
+  memcpy (m_Buffer+(4-numPutback), gptr() - numPutback, numPutback);
   int num;
   if((num = ::fread((void*)( m_Buffer + 4), 1, m_iBufferSize - 4, m_pFile)) <= 0) {
     if(errno != 0)
