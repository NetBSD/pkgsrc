$NetBSD: patch-sdk_src_posix_fs.cpp,v 1.4 2025/05/16 19:43:58 wiz Exp $

* Fix build on NetBSD, use statvfs
* Don't use mntent features on BSDs
* O_NOATIME not available on BSDs
* Fallback funcs

--- sdk/src/posix/fs.cpp.orig	2025-04-02 09:16:59.000000000 +0200
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
@@ -1018,6 +1022,18 @@ int LinuxFileSystemAccess::checkevents([
     return result;
 }
 
+#elif defined(USE_PERIODIC)
+
+void FallbackFileSystemAccess::addevents([[maybe_unused]] Waiter* waiter, int /*flags*/)
+{
+    //Nothing
+}
+
+int FallbackFileSystemAccess::checkevents([[maybe_unused]] Waiter* waiter)
+{
+    return 0;
+}
+
 #endif //  __linux__
 
 
@@ -1749,6 +1765,16 @@ void LinuxDirNotify::removeWatch(WatchMa
 }
 
 #endif // USE_INOTIFY
+
+#elif defined(USE_PERIODIC)
+
+FallbackDirNotify::FallbackDirNotify(const LocalPath& rootPath):
+    DirNotify(rootPath)
+{
+    // Let the engine know everything's ok.
+    setFailed(0, "");
+}
+
 #endif // __linux__
 
 #endif //ENABLE_SYNC
@@ -1805,8 +1831,8 @@ private:
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
@@ -2065,6 +2091,7 @@ ScanResult PosixFileSystemAccess::direct
 }
 
 #ifndef __APPLE__
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 
 // Determine which device contains the specified path.
 static std::string deviceOf(const std::string& database,
@@ -2233,6 +2260,7 @@ static std::string deviceOf(const std::s
     // No database has a mapping for this path.
     return std::string();
 }
+#endif
 
 // Compute legacy filesystem fingerprint.
 static std::uint64_t fingerprintOf(const std::string& path)
@@ -2261,6 +2289,7 @@ static std::uint64_t fingerprintOf(const
     return ++value;
 }
 
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 // Determine the UUID of the specified device.
 static std::string uuidOf(const std::string& device)
 {
@@ -2337,6 +2366,7 @@ static std::string uuidOf(const std::str
     // Couldn't determine device's UUID.
     return std::string();
 }
+#endif
 
 fsfp_t FileSystemAccess::fsFingerprint(const LocalPath& path) const
 {
@@ -2347,6 +2377,7 @@ fsfp_t FileSystemAccess::fsFingerprint(c
     if (!fingerprint)
         return fsfp_t();
 
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
     // What device contains the specified path?
     auto device = deviceOf(path.localpath);
 
@@ -2360,6 +2391,7 @@ fsfp_t FileSystemAccess::fsFingerprint(c
         if (!uuid.empty())
             return fsfp_t(fingerprint, std::move(uuid));
     }
+#endif
 
     // Couldn't determine filesystem UUID.
     return fsfp_t(fingerprint, std::string());
@@ -2452,6 +2484,15 @@ DirNotify* LinuxFileSystemAccess::newdir
     return new LinuxDirNotify(*this, root, rootPath);
 }
 #endif
+
+#elif defined(USE_PERIODIC)
+DirNotify* FallbackFileSystemAccess::newdirnotify(LocalNode& root,
+    const LocalPath& rootPath,
+    Waiter*)
+{
+    return new FallbackDirNotify(rootPath);
+}
+
 #endif
 
 bool PosixFileSystemAccess::issyncsupported(const LocalPath& localpathArg, bool& isnetwork, SyncError& syncError, SyncWarning& syncWarning)
@@ -2526,18 +2567,26 @@ bool PosixFileSystemAccess::getlocalfsty
     }
 #endif /* __linux__ || __ANDROID__ */
 
-#if defined(__APPLE__) || defined(USE_IOS)
+#if defined(__APPLE__) || defined(USE_IOS) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
+    defined(__NetBSD__) || defined(__DragonFly__)
     static const map<string, FileSystemType> filesystemTypes = {
         {"apfs",        FS_APFS},
         {"exfat",       FS_EXFAT},
+        {"ext2fs",      FS_EXT},
+        {"ffs",         FS_FFS},
+        {"hammer",      FS_HAMMER},
+        {"hammer2",     FS_HAMMER},
         {"hfs",         FS_HFS},
         {"msdos",       FS_FAT32},
+        {"msdosfs",     FS_FAT32},
         {"nfs",         FS_NFS},
         {"ntfs",        FS_NTFS}, // Apple NTFS
         {"smbfs",       FS_SMB},
         {"tuxera_ntfs", FS_NTFS}, // Tuxera NTFS for Mac
+        {"ufs",         FS_UFS},
         {"ufsd_NTFS",   FS_NTFS},  // Paragon NTFS for Mac
         {"lifs",        FS_LIFS},  // on macos (in Ventura at least), external USB with exFAT are reported as "lifs"
+        {"zfs",         FS_ZFS},
     }; /* filesystemTypes */
 
     struct statfs statbuf;
@@ -2555,7 +2604,7 @@ bool PosixFileSystemAccess::getlocalfsty
         type = FS_UNKNOWN;
         return true;
     }
-#endif /* __APPLE__ || USE_IOS */
+#endif /* __APPLE__ || USE_IOS || BSDs */
 
     type = FS_UNKNOWN;
     return false;
