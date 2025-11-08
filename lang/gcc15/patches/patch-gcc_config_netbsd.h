$NetBSD: patch-gcc_config_netbsd.h,v 1.1 2025/11/08 07:04:02 mrg Exp $

NetBSD doesn't have a -ldl.


--- gcc/config/netbsd.h.orig	2025-08-07 23:51:40.599350224 -0700
+++ gcc/config/netbsd.h	2025-11-06 12:07:01.954484996 -0800
@@ -166,3 +166,6 @@ along with GCC; see the file COPYING3.  
   do {									\
     netbsd_patch_builtins ();						\
   } while(0)
+
+/* NetBSD does not have a dl library. */
+#define DL_LIBRARY ""
