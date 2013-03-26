$NetBSD: patch-kitchensync_src_configguildap.h,v 1.1 2013/03/26 23:30:46 joerg Exp $

--- kitchensync/src/configguildap.h.orig	2013-03-26 09:28:47.000000000 +0000
+++ kitchensync/src/configguildap.h
@@ -29,7 +29,9 @@ class QCheckBox;
 class QLabel;
 class QSpinBox;
 
-class KABC::LdapConfigWidget;
+namespace KABC {
+class LdapConfigWidget;
+}
 class KComboBox;
 class KLineEdit;
 
