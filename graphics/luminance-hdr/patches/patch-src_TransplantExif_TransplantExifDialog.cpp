$NetBSD: patch-src_TransplantExif_TransplantExifDialog.cpp,v 1.3 2023/07/19 08:05:51 wiz Exp $

Fix build with exiv2 0.28.
https://github.com/LuminanceHDR/LuminanceHDR/pull/273

--- src/TransplantExif/TransplantExifDialog.cpp.orig	2019-06-09 19:18:38.000000000 +0000
+++ src/TransplantExif/TransplantExifDialog.cpp
@@ -347,7 +347,7 @@ void TransplantExifDialog::transplant_re
                 QFile::encodeName((*i_dest)).constData(),
                 m_Ui->checkBox_dont_overwrite->isChecked());
             m_Ui->rightlist->item(index)->setBackground(QBrush("#a0ff87"));
-        } catch (Exiv2::AnyError &e) {
+        } catch (Exiv2::Error &e) {
             add_log_message("ERROR:" + QString::fromStdString(e.what()));
             m_Ui->rightlist->item(index)->setBackground(QBrush("#ff743d"));
         }
