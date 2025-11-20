$NetBSD: patch-src_kar.cpp,v 1.1 2025/11/20 20:34:49 wiz Exp $

Fix build with qt6 6.10.1.
https://github.com/KDE/karchive/commit/93710faabd590ae517927c6cd4e22634fbd409db

--- src/kar.cpp.orig	2025-09-08 08:10:58.000000000 +0000
+++ src/kar.cpp
@@ -84,7 +84,7 @@ bool KAr::openArchive(QIODevice::OpenMod
         return true;
     }
     if (mode != QIODevice::ReadOnly && mode != QIODevice::ReadWrite) {
-        setErrorString(tr("Unsupported mode %1").arg(mode));
+        setErrorString(tr("Unsupported mode %1").arg(static_cast<int>(mode)));
         return false;
     }
 
