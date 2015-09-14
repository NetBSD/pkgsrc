$NetBSD: patch-kamera_kcontrol_kameradevice.cpp,v 1.1 2015/09/14 13:31:54 joerg Exp $

--- kamera/kcontrol/kameradevice.cpp.orig	2015-09-13 16:48:14.000000000 +0000
+++ kamera/kcontrol/kameradevice.cpp
@@ -346,8 +346,10 @@ KameraDeviceSelectDialog::KameraDeviceSe
 	}
 	for (int i = 0; i < gphoto_ports; i++) {
 		if (gp_port_info_list_get_info(list, i, &info) >= 0) {
-			if (strncmp(info.path, "serial:", 7) == 0)
-				m_serialPortCombo->insertItem(QString::fromLatin1(info.path).mid(7));
+			char *path;
+			gp_port_info_get_path(info, &path);
+			if (strncmp(path, "serial:", 7) == 0)
+				m_serialPortCombo->insertItem(QString::fromLatin1(path).mid(7));
 		}
 	}
 	gp_port_info_list_free(list);
