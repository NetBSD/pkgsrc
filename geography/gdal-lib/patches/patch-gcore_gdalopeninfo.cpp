$NetBSD: patch-gcore_gdalopeninfo.cpp,v 1.1 2021/09/08 22:48:13 gdt Exp $

Upstream code assumes that fopen(dir, 'r') will fail, when POSIX requires
it to succeed.  Extend the "only on FreeBSD" conditional to all systems.

Fixed differently upstream post 3.3.2 after discussion.

--- gcore/gdalopeninfo.cpp.orig	2021-09-01 09:48:45.000000000 +0000
+++ gcore/gdalopeninfo.cpp
@@ -213,12 +213,8 @@ retry:  // TODO(schwehr): Stop using got
 
 #endif  // HAVE_READLINK
 
-#ifdef __FreeBSD__
-    /* FreeBSD 8 oddity: fopen(a_directory, "rb") returns non NULL */
+    /* fopen(dir, "r") is required to succeed, per POSIX */
     bool bPotentialDirectory = (eAccess == GA_ReadOnly);
-#else
-    bool bPotentialDirectory = false;
-#endif  // __FreeBDS__
 
     /* Check if the filename might be a directory of a special virtual file system */
     if( STARTS_WITH(pszFilename, "/vsizip/") ||
