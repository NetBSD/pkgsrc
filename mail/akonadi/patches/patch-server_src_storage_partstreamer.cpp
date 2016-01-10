$NetBSD: patch-server_src_storage_partstreamer.cpp,v 1.1 2016/01/10 19:40:30 markd Exp $

From: Dan Vrátil <dvratil@redhat.com>
Date: Mon, 29 Jun 2015 20:45:11 +0000
Subject: Don't leak old external payload files
X-Git-Url: http://quickgit.kde.org/?p=akonadi.git&a=commitdiff&h=9c0dc6b3f0826d32eac310b2e7ecd858ca3df681
---
Don't leak old external payload files

Actually delete old payload files after we increase the payload revision or
switch from external to internal payload. This caused ~/.local/share/akonadi/file_db_data
to grow insanely for all users, leaving them with many duplicated files (just with
different revisions).

It is recommended that users run akonadictl fsck to clean up the leaked payload
files.

Note that there won't be any more releases of Akonadi 1.13 (and this has been
fixed in master already), so I strongly recommend distributions to pick this
patch into their packaging.

BUG: 341884
CCBUG: 338402
--- server/src/storage/partstreamer.cpp.orig	2014-08-10 10:38:58.000000000 +0000
+++ server/src/storage/partstreamer.cpp
@@ -290,6 +290,12 @@ bool PartStreamer::stream(const QByteArr
         mDataChanged = true;
     }
 
+    // If the part is external, remember it's current file name
+    QString originalFile;
+    if (part.isValid() && part.external()) {
+        originalFile = PartHelper::resolveAbsolutePath(part.data());
+    }
+
     part.setPartType(partType);
     part.setVersion(partVersion);
     part.setPimItemId(mItem.id());
@@ -306,6 +312,14 @@ bool PartStreamer::stream(const QByteArr
         *changed = mDataChanged;
     }
 
+    if (!originalFile.isEmpty()) {
+        // If the part was external but is not anymore, or if it's still external
+        // but the filename has changed (revision update), remove the original file
+        if (!part.external() || (part.external() && originalFile != PartHelper::resolveAbsolutePath(part.data()))) {
+            PartHelper::removeFile(originalFile);
+        }
+    }
+
     return ok;
 }
 
