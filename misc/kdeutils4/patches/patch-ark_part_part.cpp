$NetBSD: patch-ark_part_part.cpp,v 1.1.2.2 2011/11/20 14:42:05 tron Exp $

commit 6f6c0b18b3569ae2b5b6f65dc7ea626a8b7c03c0
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Mon Oct 17 20:40:01 2011 -0200

    Fix directory traversal issue (CVE-2011-2725).
    
    Tim Brown from Nth Dimension noticed a possible traversal issue where
    the previewer dialog would show (and then remove) the wrong file when
    a maliciously crafted archive had a file previewed.
    
    We now do the same thing as infozip and filter out "../" from the
    paths being previewed.

diff --git a/part/part.cpp b/part/part.cpp
index c213f01..b034fbf 100644
--- ark/part/part.cpp
+++ ark/part/part.cpp
@@ -504,8 +504,15 @@ void Part::slotPreviewExtracted(KJob *job)
     if (!job->error()) {
         const ArchiveEntry& entry =
             m_model->entryForIndex(m_view->selectionModel()->currentIndex());
-        const QString fullName =
-            m_previewDir->name() + '/' + entry[ FileName ].toString();
+
+        QString fullName =
+            m_previewDir->name() + QLatin1Char('/') + entry[ FileName ].toString();
+
+        // Make sure a maliciously crafted archive with parent folders named ".." do
+        // not cause the previewed file path to be located outside the temporary
+        // directory, resulting in a directory traversal issue.
+        fullName.remove(QLatin1String("../"));
+
         ArkViewer::view(fullName, widget());
     } else {
         KMessageBox::error(widget(), job->errorString());
