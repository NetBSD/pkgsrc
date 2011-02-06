$NetBSD: patch-kipi-plugins_rawconverter_rawdecodingiface.cpp,v 1.1 2011/02/06 17:06:48 wiz Exp $

Fix build with png-1.5.

--- kipi-plugins/rawconverter/rawdecodingiface.cpp.orig	2008-12-13 11:20:05.000000000 +0000
+++ kipi-plugins/rawconverter/rawdecodingiface.cpp
@@ -299,7 +299,7 @@ bool RawDecodingIface::loadedFromDcraw(c
             if (!ICCColorProfile.isEmpty())
             {
                 png_set_iCCP(png_ptr, info_ptr, "icc", PNG_COMPRESSION_TYPE_BASE, 
-                             ICCColorProfile.data(), ICCColorProfile.size());
+                             (png_bytep)ICCColorProfile.data(), ICCColorProfile.size());
             }
 
             QString libpngver(PNG_HEADER_VERSION_STRING);
