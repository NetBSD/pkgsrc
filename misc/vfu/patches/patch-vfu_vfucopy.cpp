$NetBSD: patch-vfu_vfucopy.cpp,v 1.1 2026/11/14 21:17:47 drixter Exp $

Add sys/statvfs.h and change struct from statfs to statvfs

--- vfu/vfucopy.cpp.orig
+++ vfu/vfucopy.cpp
@@ -12,6 +12,7 @@
 #include "vfusys.h"
 #include "vfucopy.h"
 #include <errno.h>
+#include <sys/statvfs.h>
 
 /****************************************************************************
 **
@@ -38,16 +39,16 @@
 
 fsize_t device_free_space( const char *target )
 {
-  struct statfs stafs;
-  int res = statfs( str_file_path( target ), &stafs );
+  struct statvfs stafs;
+  int res = statvfs( str_file_path( target ), &stafs );
   if( res == 0 ) return ((fsize_t)(stafs.f_bsize)) * stafs.f_bfree;
   return 0;
 }
 
 fsize_t device_avail_space( const char *target )
 {
-  struct statfs stafs;
-  int res = statfs( str_file_path( target ), &stafs );
+  struct statvfs stafs;
+  int res = statvfs( str_file_path( target ), &stafs );
   if( res == 0 ) return ((fsize_t)(stafs.f_bsize)) * stafs.f_bavail;
   return 0;
 }
