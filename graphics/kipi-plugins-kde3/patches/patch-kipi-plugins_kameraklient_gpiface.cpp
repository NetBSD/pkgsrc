$NetBSD: patch-kipi-plugins_kameraklient_gpiface.cpp,v 1.1 2015/09/14 13:31:54 joerg Exp $

--- kipi-plugins/kameraklient/gpiface.cpp.orig	2015-09-13 16:08:06.000000000 +0000
+++ kipi-plugins/kameraklient/gpiface.cpp
@@ -114,7 +114,9 @@ void GPIface::getSupportedPorts(QStringL
     int numPorts = gp_port_info_list_count( list );
     for (int i = 0; i < numPorts; i++) {
         gp_port_info_list_get_info( list, i, &info );
-        plist.append( info.path );
+        char *path;
+        gp_port_info_get_path(info, &path);
+        plist.append( path );
     }
     gp_port_info_list_free( list );
 }
