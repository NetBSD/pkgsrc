$NetBSD: patch-src_program__files.cc,v 1.1 2011/12/19 15:52:21 wiz Exp $

Fix namespace.

--- src/program_files.cc.orig	2005-08-25 21:57:41.000000000 +0000
+++ src/program_files.cc
@@ -136,7 +136,7 @@ ProgramFileBuf::int_type ProgramFileBuf:
   if (numPutback > 4) {
     numPutback = 4;
   }
-  std::memcpy (m_Buffer+(4-numPutback), gptr() - numPutback, numPutback);
+  memcpy (m_Buffer+(4-numPutback), gptr() - numPutback, numPutback);
 
   int num;
   if((num = ::fread((void*)( m_Buffer + 4), 1, m_iBufferSize - 4, m_pFile)) <= 0) {
