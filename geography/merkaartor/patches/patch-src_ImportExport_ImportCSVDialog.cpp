$NetBSD: patch-src_ImportExport_ImportCSVDialog.cpp,v 1.1 2013/08/27 15:51:27 joerg Exp $

--- src/ImportExport/ImportCSVDialog.cpp.orig	2013-08-27 15:03:55.000000000 +0000
+++ src/ImportExport/ImportCSVDialog.cpp
@@ -518,7 +518,7 @@ void ImportCSVDialog::on_btSave_clicked(
     if (tDelim == "\t")
         tDelim = "tab";
     root.setAttribute("delimiter", tDelim);
-    root.setAttribute("header", ui->cbHasHeader->isChecked() ? "true" : false);
+    root.setAttribute("header", ui->cbHasHeader->isChecked() ? "true" : "false");
     root.setAttribute("from", QString::number(ui->sbFrom->value()));
     root.setAttribute("to", QString::number(ui->sbTo->value()));
 
