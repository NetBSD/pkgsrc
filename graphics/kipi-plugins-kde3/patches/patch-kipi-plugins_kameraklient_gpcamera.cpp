$NetBSD: patch-kipi-plugins_kameraklient_gpcamera.cpp,v 1.1 2015/09/14 13:31:54 joerg Exp $

--- kipi-plugins/kameraklient/gpcamera.cpp.orig	2015-09-13 15:58:37.000000000 +0000
+++ kipi-plugins/kameraklient/gpcamera.cpp
@@ -436,7 +436,12 @@ int GPCamera::uploadItem(const QString& 
         status = 0;
     }
     status = new GPStatus;
-    if (gp_camera_folder_put_file(d->camera, folder.latin1(), cfile, status->context) != GP_OK) {
+    if (gp_camera_folder_put_file(d->camera,
+                                  QFile::encodeName(folder),
+                                  QFile::encodeName(itemName),
+                                  GP_FILE_TYPE_NORMAL,
+                                  cfile,
+                                  status->context) != GP_OK) {
         gp_file_unref(cfile);
         delete status;
         status = 0;
@@ -530,7 +535,9 @@ void GPCamera::getSupportedPorts(QString
     int numPorts = gp_port_info_list_count( list );
     for (int i = 0; i < numPorts; i++) {
         gp_port_info_list_get_info( list, i, &info );
-        plist.append(info.path);
+        char *path;
+        gp_port_info_get_path(info, &path);
+        plist.append(path);
     }
     gp_port_info_list_free( list );
 }
