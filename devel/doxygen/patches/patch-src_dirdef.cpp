$NetBSD: patch-src_dirdef.cpp,v 1.6 2026/08/20 07:48:05 adam Exp $

Doxygen encodes the source directory path into some of the output filenames.
This is problematic in a pkgsrc context as it means WRKDIR pathnames can appear
in generated filenames.

--- src/dirdef.cpp.orig	2026-08-13 11:44:36.000000000 +0000
+++ src/dirdef.cpp
@@ -224,8 +224,8 @@ static DString encodeDirName(const DStri
 
 DString DirDefImpl::getOutputFileBase() const
 {
-  DString dir = "dir_"+encodeDirName(m_diskName);
-  AUTO_TRACE("diskName={} result={}",m_diskName,dir);
+  DString dir = "dir_"+encodeDirName(m_shortName);
+  AUTO_TRACE("diskName={} result={}",m_shortName,dir);
   return dir;
 }
 
