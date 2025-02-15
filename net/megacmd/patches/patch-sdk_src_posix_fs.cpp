$NetBSD: patch-sdk_src_posix_fs.cpp,v 1.3 2025/02/15 07:40:14 wiz Exp $

* Fix build on NetBSD, use statvfs
* Don't use mntent features on BSDs
* O_NOATIME not available on BSDs
* BSDs use LinuxFileSystemAccess

--- sdk/src/posix/fs.cpp.orig	2025-01-24 13:56:57.000000000 +0100
+++ sdk/src/posix/fs.cpp
@@ -22,7 +22,8 @@
  * You should have received a copy of the license along with this
  * program.
  */
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && \
+    !defined(__NetBSD__) && !defined(__DragonFly__)
 #include <mntent.h>
 #endif // ! __APPLE__
 
@@ -32,6 +33,9 @@
 #include <sys/ioctl.h>
 #include <sys/resource.h>
 #include <sys/statvfs.h>
+#if defined(__NetBSD__)
+#define statfs statvfs
+#endif
 #include <sys/types.h>
 #include <sys/utsname.h>
 #ifdef TARGET_OS_MAC
@@ -818,7 +822,8 @@ PosixFileSystemAccess::PosixFileSystemAc
     defaultfolderpermissions = 0700;
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
+    defined(__NetBSD__) || defined(__DragonFly__)
 #ifdef ENABLE_SYNC
 
 bool LinuxFileSystemAccess::initFilesystemNotificationSystem()
@@ -878,7 +883,8 @@ bool PosixFileSystemAccess::cwd_static(L
 
 // wake up from filesystem updates
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
+    defined(__NetBSD__) || defined(__DragonFly__)
 void LinuxFileSystemAccess::addevents([[maybe_unused]] Waiter* waiter, int /*flags*/)
 {
 #ifdef ENABLE_SYNC
@@ -1637,7 +1643,8 @@ void PosixFileSystemAccess::statsid(stri
 }
 
 #if defined(ENABLE_SYNC)
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
+    defined(__NetBSD__) || defined(__DragonFly__)
 
 LinuxDirNotify::LinuxDirNotify(LinuxFileSystemAccess& owner,
                                LocalNode& /*root*/,
@@ -1802,8 +1809,8 @@ private:
     // open with O_NOATIME if possible
     int open(const char *path)
     {
-#ifdef TARGET_OS_IPHONE
-        // building for iOS, there is no O_NOATIME flag
+#ifndef O_NOATIME
+        // building for iOS and BSDs, there is no O_NOATIME flag
         int fd = ::open(path, O_RDONLY) ;
 #else
         // for sync in particular, try to open without setting access-time
@@ -2062,6 +2069,7 @@ ScanResult PosixFileSystemAccess::direct
 }
 
 #ifndef __APPLE__
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 
 // Determine which device contains the specified path.
 static std::string deviceOf(const std::string& database,
@@ -2230,6 +2238,7 @@ static std::string deviceOf(const std::s
     // No database has a mapping for this path.
     return std::string();
 }
+#endif
 
 // Compute legacy filesystem fingerprint.
 static std::uint64_t fingerprintOf(const std::string& path)
@@ -2258,6 +2267,7 @@ static std::uint64_t fingerprintOf(const
     return ++value;
 }
 
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 // Determine the UUID of the specified device.
 static std::string uuidOf(const std::string& device)
 {
@@ -2334,6 +2344,7 @@ static std::string uuidOf(const std::str
     // Couldn't determine device's UUID.
     return std::string();
 }
+#endif
 
 fsfp_t FileSystemAccess::fsFingerprint(const LocalPath& path) const
 {
@@ -2344,6 +2355,7 @@ fsfp_t FileSystemAccess::fsFingerprint(c
     if (!fingerprint)
         return fsfp_t();
 
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
     // What device contains the specified path?
     auto device = deviceOf(path.localpath);
 
@@ -2360,6 +2372,7 @@ fsfp_t FileSystemAccess::fsFingerprint(c
 
     LOG_warn << "Falling back to legacy filesystem fingerprint: "
              << path;
+#endif
 
     // Couldn't determine filesystem UUID.
     return fsfp_t(fingerprint, std::string());
@@ -2419,7 +2432,8 @@ unique_ptr<DirAccess>  PosixFileSystemAc
     return unique_ptr<DirAccess>(new PosixDirAccess());
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
+    defined(__NetBSD__) || defined(__DragonFly__)
 #ifdef ENABLE_SYNC
 DirNotify* LinuxFileSystemAccess::newdirnotify(LocalNode& root,
     const LocalPath& rootPath,
