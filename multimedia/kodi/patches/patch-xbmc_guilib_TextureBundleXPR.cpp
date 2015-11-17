$NetBSD: patch-xbmc_guilib_TextureBundleXPR.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/guilib/TextureBundleXPR.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/guilib/TextureBundleXPR.cpp
@@ -288,7 +288,7 @@ bool CTextureBundleXPR::LoadFile(const s
     GlobalMemoryStatusEx(&stat);
     CLog::Log(LOGERROR, "Out of memory loading texture: %s (need %lu bytes, have %" PRIu64" bytes)", name.c_str(),
               file->second.UnpackedSize + file->second.PackedSize, stat.ullAvailPhys);
-#elif defined(TARGET_DARWIN) || defined(TARGET_FREEBSD)
+#elif defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
     CLog::Log(LOGERROR, "Out of memory loading texture: %s (need %d bytes)", name.c_str(),
               file->second.UnpackedSize + file->second.PackedSize);
 #else
