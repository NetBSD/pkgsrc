$NetBSD: patch-unix-osutil.cxx,v 1.3 2012/12/01 15:28:03 darcy Exp $

- Add DragonFly support

--- src/ptlib/unix/osutil.cxx.orig	2012-08-23 02:12:27.000000000 +0000
+++ src/ptlib/unix/osutil.cxx
@@ -80,7 +80,7 @@
 #define P_USE_LANGINFO
 #endif
 
-#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS)
+#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_DRAGONFLY)
 #define P_USE_STRFTIME
 
 #include <sys/param.h>
@@ -535,7 +535,7 @@ PString PDirectory::GetVolume() const
     }
     fclose(fp);
 
-#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS)
+#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(P_DRAGONFLY)
 
     struct statfs * mnt;
     int count = getmntinfo(&mnt, MNT_NOWAIT);
@@ -1452,7 +1452,7 @@ int PTime::GetTimeZone(PTime::TimeZoneTy
     return tz;
   else
     return tz + ::daylight*60;
-#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(__BEOS__) || defined(P_QNX) || defined(P_GNU_HURD)
+#elif defined(P_FREEBSD) || defined(P_OPENBSD) || defined(P_NETBSD) || defined(P_MACOSX) || defined(P_MACOS) || defined(__BEOS__) || defined(P_QNX) || defined(P_GNU_HURD) || defined(P_DRAGONFLY)
   time_t t;
   time(&t);
   struct tm ts;
