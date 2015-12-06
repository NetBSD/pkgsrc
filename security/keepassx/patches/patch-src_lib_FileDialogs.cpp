$NetBSD: patch-src_lib_FileDialogs.cpp,v 1.1 2015/12/06 14:20:34 wiz Exp $

Description: Abort file save dialog gracefully on 'cancel'
Author: Reinhard Tartler <siretart@debian.org>
Bug-Debian: 791858

The Qt documentation says that pressing the "Cancel" button "returns a
null string" (cf http://doc.qt.io/qt-4.8/qfiledialog.html#details). The
default (and only) implementation of the File dialog ignores this case
and wrongly constructs a bogus filename. This patch bails out gracefully
and avoids cleartext passwords on the hard disk.

Fixes CVE-2015-8378

https://anonscm.debian.org/cgit/collab-maint/keepassx.git/commit/?id=b3c9028db8ec3b8752ff47717ffc792d755c1294

--- src/lib/FileDialogs.cpp.orig	2009-10-08 19:27:39.000000000 +0000
+++ src/lib/FileDialogs.cpp
@@ -118,6 +118,10 @@ QString QtStandardFileDialogs::saveFileD
 		SelectedFilter=Filters[SelectedFilterIndex];
 	QString filepath = QFileDialog::getSaveFileName(parent,title,dir,toSingleStringFilter(Filters),&SelectedFilter,
 	                                                ShowOverwriteWarning ? (QFileDialog::Option)0 : QFileDialog::DontConfirmOverwrite);
+	// Fixes CVE-2015-8378
+	if (filepath.isEmpty())
+		return filepath;
+
 	LastFilter=Filters.indexOf(SelectedFilter);
 		
 	//Check whether the file has an extension which fits to the selected filter
