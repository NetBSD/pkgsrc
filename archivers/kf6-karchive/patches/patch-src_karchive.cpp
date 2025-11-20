$NetBSD: patch-src_karchive.cpp,v 1.1 2025/11/20 20:34:49 wiz Exp $

Fix build with qt6 6.10.1.
https://github.com/KDE/karchive/commit/93710faabd590ae517927c6cd4e22634fbd409db

--- src/karchive.cpp.orig	2025-09-08 08:10:58.000000000 +0000
+++ src/karchive.cpp
@@ -159,7 +159,7 @@ bool KArchive::open(QIODevice::OpenMode 
     }
 
     if (!d->dev->isOpen() && !d->dev->open(mode)) {
-        setErrorString(tr("Could not open device in mode %1").arg(mode));
+        setErrorString(tr("Could not open device in mode %1").arg(static_cast<int>(mode)));
         return false;
     }
 
@@ -205,7 +205,7 @@ bool KArchive::createDevice(QIODevice::O
         }
         break; // continued below
     default:
-        setErrorString(tr("Unsupported mode %1").arg(d->mode));
+        setErrorString(tr("Unsupported mode %1").arg(static_cast<int>(mode)));
         return false;
     }
     return true;
