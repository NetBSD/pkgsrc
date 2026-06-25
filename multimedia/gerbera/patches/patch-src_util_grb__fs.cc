$NetBSD: patch-src_util_grb__fs.cc,v 1.1 2026/06/25 08:16:53 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/util/grb_fs.cc.orig	2026-06-25 08:05:39.961557093 +0000
+++ src/util/grb_fs.cc
@@ -167,7 +167,7 @@ std::FILE* GrbFile::open(const char* mode, bool fail)
     if (!fd) {
         if (fail)
             throw_fmt_system_error("Could not open {}", path.c_str());
-        log_error("Could not open {}: {}", path.c_str(), std::strerror(errno));
+        log_error("Could not open {}: {}", path.c_str(), strerror(errno));
     }
     return fd;
 }
@@ -245,7 +245,7 @@ void GrbFile::setPermissions()
 {
     auto err = chmod(path.c_str(), S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
     if (err != 0) {
-        log_error("Failed to change location {} permissions: {}", path.c_str(), std::strerror(errno));
+        log_error("Failed to change location {} permissions: {}", path.c_str(), strerror(errno));
     }
 }
 
@@ -253,7 +253,7 @@ bool GrbFile::isWritable()
 {
     auto err = access(path.c_str(), R_OK | W_OK);
     if (err != 0 && errno != ENOENT) {
-        log_error("Failed to check file {} write permissions: {}", path.c_str(), std::strerror(errno));
+        log_error("Failed to check file {} write permissions: {}", path.c_str(), strerror(errno));
         return false;
     }
     return true;
@@ -264,7 +264,7 @@ bool GrbFile::isReadable(bool warn)
     auto err = access(path.c_str(), R_OK);
     if (err != 0) {
         if (warn)
-            log_error("Failed to check file {} read permissions: {}", path.c_str(), std::strerror(errno));
+            log_error("Failed to check file {} read permissions: {}", path.c_str(), strerror(errno));
         return false;
     }
     return true;
@@ -280,7 +280,7 @@ bool isTheora(const fs::path& oggFilename)
         throw_std_runtime_error("Error reading {}", oggFilename.c_str());
     }
 
-    if (std::memcmp(buffer, "OggS", 4) != 0) {
+    if (memcmp(buffer, "OggS", 4) != 0) {
         return false;
     }
 
@@ -292,7 +292,7 @@ bool isTheora(const fs::path& oggFilename)
         throw_std_runtime_error("Error reading {}", oggFilename.c_str());
     }
 
-    return std::memcmp(buffer, "\x80theora", 7) == 0;
+    return memcmp(buffer, "\x80theora", 7) == 0;
 }
 
 fs::path getLastPath(const fs::path& path)
@@ -316,11 +316,11 @@ std::string getAVIFourCC(const fs::path& aviFilename)
 
     buffer[FCC_OFFSET + 5] = '\0';
 
-    if (std::strncmp(buffer, "RIFF", 4) != 0) {
+    if (strncmp(buffer, "RIFF", 4) != 0) {
         return {};
     }
 
-    if (std::strncmp(buffer + 8, "AVI ", 4) != 0) {
+    if (strncmp(buffer + 8, "AVI ", 4) != 0) {
         return {};
     }
 
