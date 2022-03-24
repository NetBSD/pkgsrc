$NetBSD: patch-src_ltfs_fuse.c,v 1.1 2022/03/24 16:35:31 manu Exp $

Do not take for granted that __WORDSIZE is defined to distinguish 
between 32 and 64 bit platforms. Instead use ULONG_MAX from <limits.h>
which is mandared by ISO C99.

--- src/ltfs_fuse.c.orig	2022-03-24 10:08:47.455171288 +0100
+++ src/ltfs_fuse.c	2022-03-24 10:21:27.627832669 +0100
@@ -53,8 +53,11 @@
 **                  piste@jp.ibm.com
 **
 *************************************************************************************
 */
+
+#include <limits.h> /* for ULONG_MAX */
+
 #include "ltfs_fuse.h"
 #include "libltfs/ltfs_fsops.h"
 #include "libltfs/iosched.h"
 #include "libltfs/pathname.h"
@@ -67,9 +70,9 @@
 #ifdef mingw_PLATFORM
 #include "libltfs/arch/win/win_util.h"
 #endif
 
-#if (__WORDSIZE == 64)
+#if (__WORDSIZE == 64 || ULONG_MAX == 0xffffffffffffffffUL)
 #define FILEHANDLE_TO_STRUCT(fh) ((struct ltfs_file_handle *)(uint64_t)(fh))
 #define STRUCT_TO_FILEHANDLE(de) ((uint64_t)(de))
 #else
 #define FILEHANDLE_TO_STRUCT(fh) ((struct ltfs_file_handle *)(uint32_t)(fh))
