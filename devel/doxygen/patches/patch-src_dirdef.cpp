$NetBSD: patch-src_dirdef.cpp,v 1.5 2023/12/31 09:48:43 wiz Exp $

Doxygen encodes the source directory path into some of the output filenames.
This is problematic in a pkgsrc context as it means WRKDIR pathnames can appear
in generated filenames.

--- src/dirdef.cpp.orig	2023-12-31 08:43:03.452447140 +0000
+++ src/dirdef.cpp
@@ -220,7 +220,7 @@ static QCString encodeDirName(const QCSt
 
 QCString DirDefImpl::getOutputFileBase() const
 {
-  QCString dir = "dir_"+encodeDirName(m_diskName);
+  QCString dir = "dir_"+encodeDirName(m_shortName);
   AUTO_TRACE("diskName={} result={}",m_diskName,dir);
   return dir;
 }
