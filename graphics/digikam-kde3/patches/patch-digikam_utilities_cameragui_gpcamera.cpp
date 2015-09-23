$NetBSD: patch-digikam_utilities_cameragui_gpcamera.cpp,v 1.1 2015/09/23 11:53:00 joerg Exp $

--- digikam/utilities/cameragui/gpcamera.cpp.orig	2015-09-20 17:16:43.000000000 +0000
+++ digikam/utilities/cameragui/gpcamera.cpp
@@ -847,6 +847,8 @@ bool GPCamera::uploadItem(const QString&
 
     errorCode = gp_camera_folder_put_file(d->camera,
                                           QFile::encodeName(folder),
+                                          QFile::encodeName(itemName),
+                                          GP_FILE_TYPE_NORMAL,
                                           cfile,
                                           m_status->context);
     if (errorCode != GP_OK) 
@@ -1108,7 +1110,9 @@ void GPCamera::getSupportedPorts(QString
         for (int i = 0 ; i < numPorts ; i++) 
         {
             gp_port_info_list_get_info( list, i, &info );
-            plist.append( info.path );
+            char *path;
+            gp_port_info_get_path(info, &path);
+            plist.append(path);
         }
     }
 
