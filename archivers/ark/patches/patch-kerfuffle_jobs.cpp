$NetBSD: patch-kerfuffle_jobs.cpp,v 1.1 2020/09/20 11:05:31 markd Exp $

https://kde.org/info/security/advisory-20200730-1.txt
A maliciously crafted archive with "../" in the file paths would
install files anywhere in the user's home directory upon extraction.

--- kerfuffle/jobs.cpp.orig	2020-05-11 21:15:07.000000000 +0000
+++ kerfuffle/jobs.cpp
@@ -181,6 +181,13 @@ void Job::onError(const QString & messag
 
 void Job::onEntry(Archive::Entry *entry)
 {
+    const QString entryFullPath = entry->fullPath();
+    if (QDir::cleanPath(entryFullPath).contains(QLatin1String("../"))) {
+        qCWarning(ARK) << "Possibly malicious archive. Detected entry that could lead to a directory traversal attack:" << entryFullPath;
+        onError(i18n("Could not load the archive because it contains ill-formed entries and might be a malicious archive."), QString());
+        onFinished(false);
+        return;
+    }
     emit newEntry(entry);
 }
 
