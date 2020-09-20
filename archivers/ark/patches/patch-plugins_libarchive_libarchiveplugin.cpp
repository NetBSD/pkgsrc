$NetBSD: patch-plugins_libarchive_libarchiveplugin.cpp,v 1.1 2020/09/20 11:05:31 markd Exp $

https://kde.org/info/security/advisory-20200827-1.txt
A maliciously crafted TAR archive containing symlink entries would
install files anywhere in the user's home directory upon extraction.

--- plugins/libarchive/libarchiveplugin.cpp.orig	2020-05-11 21:15:07.000000000 +0000
+++ plugins/libarchive/libarchiveplugin.cpp
@@ -509,21 +509,9 @@ void LibarchivePlugin::emitEntryFromArch
 
 int LibarchivePlugin::extractionFlags() const
 {
-    int result = ARCHIVE_EXTRACT_TIME;
-    result |= ARCHIVE_EXTRACT_SECURE_NODOTDOT;
-
-    // TODO: Don't use arksettings here
-    /*if ( ArkSettings::preservePerms() )
-    {
-        result &= ARCHIVE_EXTRACT_PERM;
-    }
-
-    if ( !ArkSettings::extractOverwrite() )
-    {
-        result &= ARCHIVE_EXTRACT_NO_OVERWRITE;
-    }*/
-
-    return result;
+    return ARCHIVE_EXTRACT_TIME
+           | ARCHIVE_EXTRACT_SECURE_NODOTDOT
+           | ARCHIVE_EXTRACT_SECURE_SYMLINKS;
 }
 
 void LibarchivePlugin::copyData(const QString& filename, struct archive *dest, bool partialprogress)
