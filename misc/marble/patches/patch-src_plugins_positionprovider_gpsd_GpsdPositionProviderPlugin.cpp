$NetBSD: patch-src_plugins_positionprovider_gpsd_GpsdPositionProviderPlugin.cpp,v 1.1 2020/09/23 22:18:28 markd Exp $

Handle gpsd>=3.21

--- src/plugins/positionprovider/gpsd/GpsdPositionProviderPlugin.cpp.orig	2020-05-11 07:18:57.000000000 +0000
+++ src/plugins/positionprovider/gpsd/GpsdPositionProviderPlugin.cpp
@@ -79,7 +79,11 @@ void GpsdPositionProviderPlugin::update(
 {
     PositionProviderStatus oldStatus = m_status;
     GeoDataCoordinates oldPosition = m_position;
+#if defined( GPSD_API_MAJOR_VERSION ) && ( GPSD_API_MAJOR_VERSION >= 10 )
+    if ( data.fix.status == STATUS_NO_FIX || std::isnan( data.fix.longitude ) || std::isnan( data.fix.latitude ) )
+#else
     if ( data.status == STATUS_NO_FIX || std::isnan( data.fix.longitude ) || std::isnan( data.fix.latitude ) )
+#endif
         m_status = PositionProviderStatusAcquiring;
     else {
         m_status = PositionProviderStatusAvailable;
