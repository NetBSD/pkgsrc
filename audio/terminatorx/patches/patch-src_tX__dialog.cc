$NetBSD: patch-src_tX__dialog.cc,v 1.1 2019/10/05 12:09:26 nia Exp $

Fix function argument list when building without ALSA.

--- src/tX_dialog.cc.orig	2016-07-24 14:24:08.000000000 +0000
+++ src/tX_dialog.cc
@@ -244,7 +244,7 @@ void append_alsa_device_list(GtkComboBox
 	}
 }
 #else
-void append_alsa_device_list(GtkComboBoxText *combo) {
+void append_alsa_device_list(GtkComboBoxText *combo, char *current) {
 }
 #endif
 
