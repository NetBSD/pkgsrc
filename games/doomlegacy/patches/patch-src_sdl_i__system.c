$NetBSD: patch-src_sdl_i__system.c,v 1.1 2019/06/17 13:53:22 micha Exp $

Use statvfs(5) for NetBSD.

--- src/sdl/i_system.c.orig	2017-03-03 20:22:35.000000000 +0000
+++ src/sdl/i_system.c
@@ -74,7 +74,7 @@
    // meminfo
 #  include <sys/types.h>
 #  include <sys/sysctl.h>
-# elif defined( __MACH__ )
+# elif defined( __MACH__ ) || defined( NETBSD )
 #  include <sys/statvfs.h>
 # else
 #  include <sys/vfs.h>
@@ -861,7 +861,7 @@ uint64_t I_GetDiskFreeSpace(void)
 # ifdef SOLARIS
   goto guess;
 
-# elif defined( __MACH__ )
+# elif defined( __MACH__ ) || defined( NETBSD )
   struct statvfs stfs;
   if (statvfs(".", &stfs) == -1)
     goto guess;
