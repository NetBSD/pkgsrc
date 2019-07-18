$NetBSD: patch-help.c,v 1.1 2019/07/18 12:15:04 nia Exp $

Use statvfs on NetBSD.

--- help.c.orig	2019-01-10 08:40:57.000000000 +0000
+++ help.c
@@ -30,9 +30,11 @@
 #if defined(_MSC_VER) && _MSC_VER < 1900
 	#define snprintf _snprintf
 #endif
-#elif defined(__macosx__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__macosx__) || defined(__FreeBSD__) || defined(__OpenBSD__)
     #include <sys/param.h>
     #include <sys/mount.h>
+#elif defined(__NetBSD__)
+    #include <sys/statvfs.h>
 #elif defined (__linux__) || defined(__SYLLABLE__)
     #include <sys/vfs.h>
 #elif defined (__HAIKU__)
@@ -966,12 +968,18 @@ void Button_Stats(int btn)
       GetDiskFreeSpaceExA(Main.selector.Directory,&tailleU,NULL,NULL);
       mem_size = tailleU.QuadPart;
     }
-#elif defined(__linux__) || defined(__macosx__) || defined(__FreeBSD__) || defined(__SYLLABLE__) || defined(__AROS__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__linux__) || defined(__macosx__) || defined(__FreeBSD__) || defined(__SYLLABLE__) || defined(__AROS__) || defined(__OpenBSD__)
     {
       struct statfs disk_info;
       statfs(Main.selector.Directory,&disk_info);
       mem_size=(qword) disk_info.f_bfree * (qword) disk_info.f_bsize;
     }
+#elif defined(__NetBSD__)
+    {
+      struct statvfs disk_info;
+      statvfs(Main.selector.Directory,&disk_info);
+      mem_size=(qword) disk_info.f_bfree * (qword) disk_info.f_bsize;
+    }
 #elif defined(__HAIKU__)
    mem_size = haiku_get_free_space(Main.selector.Directory);
 #elif defined (__MINT__)
