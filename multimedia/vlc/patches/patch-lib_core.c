$NetBSD: patch-lib_core.c,v 1.1 2019/07/02 20:52:13 nia Exp $

For unknown reason disable duplicated symbol for vlc_module_name.

--- lib/core.c.orig	2017-11-24 15:29:17.000000000 +0000
+++ lib/core.c
@@ -257,4 +257,4 @@ int64_t libvlc_clock(void)
     return mdate();
 }
 
-const char vlc_module_name[] = "libvlc";
+// const char vlc_module_name[] = "libvlc";
