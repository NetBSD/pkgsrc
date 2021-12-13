$NetBSD: patch-src_dirdef.cpp,v 1.2 2021/12/13 13:47:06 micha Exp $

Doxygen encodes the source directory path into some of the output filenames.
This is problematic in a pkgsrc context as it means WRKDIR pathnames can appear
in generated filenames. Fix by reverting to the old way of naming the files.

--- src/dirdef.cpp.orig	2021-08-17 17:10:43.000000000 +0000
+++ src/dirdef.cpp
@@ -211,7 +211,7 @@ QCString DirDefImpl::getOutputFileBase()
 {
   //printf("DirDefImpl::getOutputFileBase() %s->dir_%s\n",
   //    qPrint(m_diskName),qPrint(encodeDirName(m_diskName)));
-  return "dir_"+encodeDirName(m_diskName);
+  return QCString().sprintf("dir_%06d",m_dirCount);
 }
 
 void DirDefImpl::writeDetailedDescription(OutputList &ol,const QCString &title)
