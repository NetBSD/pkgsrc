$NetBSD: patch-src_dirdef.cpp,v 1.4 2023/05/19 10:37:20 adam Exp $

Doxygen encodes the source directory path into some of the output filenames.
This is problematic in a pkgsrc context as it means WRKDIR pathnames can appear
in generated filenames. Fix by reverting to the old way of naming the files.

--- src/dirdef.cpp.orig	2023-04-10 11:37:44.000000000 +0000
+++ src/dirdef.cpp
@@ -215,7 +215,7 @@ static QCString encodeDirName(const QCSt
 
 QCString DirDefImpl::getOutputFileBase() const
 {
-  QCString dir = "dir_"+encodeDirName(m_diskName);
+  QCString dir = QCString().sprintf("dir_%06d",m_dirCount);
   AUTO_TRACE("diskName={} result={}",m_diskName,dir);
   return dir;
 }
