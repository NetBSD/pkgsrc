$NetBSD: patch-src_core_raster_qgsexiftools.cpp,v 1.1 2023/07/19 05:22:18 wiz Exp $

exiv2 0.28.0 support based on https://github.com/qgis/QGIS/commit/32f5418fc4f7bb2ee986dee1824ff2989c113a94

--- src/core/raster/qgsexiftools.cpp.orig	2023-05-26 12:01:31.000000000 +0000
+++ src/core/raster/qgsexiftools.cpp
@@ -94,7 +94,11 @@ QVariant decodeExifData( const QString &
       case Exiv2::signedLong:
       case Exiv2::unsignedLongLong:
       case Exiv2::signedLongLong:
+#if EXIV2_TEST_VERSION (0, 28, 0)
+        val = QVariant::fromValue( it->toUint32() );
+#else
         val = QVariant::fromValue( it->toLong() );
+#endif
         break;
 
       case Exiv2::tiffDouble:
@@ -108,7 +112,11 @@ QVariant decodeExifData( const QString &
       case Exiv2::signedByte:
       case Exiv2::tiffIfd:
       case Exiv2::tiffIfd8:
+#if EXIV2_TEST_VERSION (0, 28, 0)
+        val = QVariant::fromValue( static_cast< int >( it->toUint32() ) );
+#else
         val = QVariant::fromValue( static_cast< int >( it->toLong() ) );
+#endif
         break;
 
       case Exiv2::date:
