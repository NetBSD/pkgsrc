$NetBSD: patch-src_dirdef.cpp,v 1.1 2019/10/17 20:35:58 adam Exp $

Doxygen encodes the source directory path into some of the output filenames.
This is problematic in a pkgsrc context as it means WRKDIR pathnames can appear
in generated filenames. Fix by reverting to the old way of naming the files.

--- src/dirdef.cpp.orig	2019-06-13 19:36:00.000000000 +0000
+++ src/dirdef.cpp
@@ -198,7 +198,7 @@ QCString DirDefImpl::getOutputFileBase()
 {
   //printf("DirDefImpl::getOutputFileBase() %s->dir_%s\n",
   //    m_diskName.data(),encodeDirName(m_diskName).data());
-  return "dir_"+encodeDirName(m_diskName);
+  return QCString().sprintf("dir_%06d",m_dirCount);
 }
 
 void DirDefImpl::writeDetailedDescription(OutputList &ol,const QCString &title)
