$NetBSD: patch-xbmc_guilib_XBTFReader.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/guilib/XBTFReader.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/guilib/XBTFReader.cpp
@@ -189,7 +189,7 @@ bool CXBTFReader::Load(const CXBTFFrame&
   {
     return false;
   }
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_ANDROID)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD) || defined(TARGET_ANDROID)
     if (fseeko(m_file, (off_t)frame.GetOffset(), SEEK_SET) == -1)
 #else
     if (fseeko64(m_file, (off_t)frame.GetOffset(), SEEK_SET) == -1)
