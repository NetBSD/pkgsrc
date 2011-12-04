$NetBSD: patch-unix-osutil.cxx,v 1.1 2011/12/04 21:59:37 marino Exp $

--- src/ptlib/unix/osutil.cxx.orig	2009-09-21 00:25:17.000000000 +0000
+++ src/ptlib/unix/osutil.cxx
@@ -79,7 +79,7 @@
 #define P_USE_LANGINFO
 #endif
 
-#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS)
+#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_DRAGONFLY)
 #define P_USE_STRFTIME
 
 #include <sys/param.h>
@@ -534,7 +534,7 @@ PString PDirectory::GetVolume() const
     }
     fclose(fp);
 
-#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS)
+#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_DRAGONFLY)
 
     struct statfs * mnt;
     int count = getmntinfo(&mnt, MNT_NOWAIT);
@@ -574,7 +574,7 @@ PString PDirectory::GetVolume() const
 
 PBoolean PDirectory::GetVolumeSpace(PInt64 & total, PInt64 & free, DWORD & clusterSize) const
 {
-#if defined(P_LINUX) || defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS)
+#if defined(P_LINUX) || defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_DRAGONFLY)
 
   struct statfs fs;
 
@@ -1429,7 +1429,7 @@ int PTime::GetTimeZone(PTime::TimeZoneTy
     return tz;
   else
     return tz + ::daylight*60;
-#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(__BEOS__) || defined(P_QNX)
+#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(__BEOS__) || defined(P_QNX) || defined(P_DRAGONFLY)
   time_t t;
   time(&t);
   struct tm ts;
