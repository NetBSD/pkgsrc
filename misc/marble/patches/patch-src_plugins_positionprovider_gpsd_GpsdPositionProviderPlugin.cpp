$NetBSD: patch-src_plugins_positionprovider_gpsd_GpsdPositionProviderPlugin.cpp,v 1.3 2021/12/17 08:51:53 prlw1 Exp $

Fix build with gpsd 3.23.1
STATUS_NO_FIX was renamed to STATUS_UNK.
https://invent.kde.org/education/marble/-/commit/8aadc3eb8f9484a65d497d442cd8c61fe1462bef

--- src/plugins/positionprovider/gpsd/GpsdPositionProviderPlugin.cpp.orig	2021-02-27 00:23:23.000000000 +0000
+++ src/plugins/positionprovider/gpsd/GpsdPositionProviderPlugin.cpp
@@ -79,7 +79,9 @@ void GpsdPositionProviderPlugin::update(
 {
     PositionProviderStatus oldStatus = m_status;
     GeoDataCoordinates oldPosition = m_position;
-#if defined( GPSD_API_MAJOR_VERSION ) && ( GPSD_API_MAJOR_VERSION >= 10 )
+#if defined(STATUS_UNK) // STATUS_NO_FIX was renamed to STATUS_UNK without bumping API version
+    if ( data.fix.status == STATUS_UNK || std::isnan( data.fix.longitude ) || std::isnan( data.fix.latitude ) )
+#elif defined( GPSD_API_MAJOR_VERSION ) && ( GPSD_API_MAJOR_VERSION >= 10 )
     if ( data.fix.status == STATUS_NO_FIX || std::isnan( data.fix.longitude ) || std::isnan( data.fix.latitude ) )
 #else
     if ( data.status == STATUS_NO_FIX || std::isnan( data.fix.longitude ) || std::isnan( data.fix.latitude ) )
