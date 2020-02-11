$NetBSD: patch-help.c,v 1.3 2020/02/11 02:38:37 ryoon Exp $

Use statvfs on NetBSD.
https://gitlab.com/GrafX2/grafX2/-/merge_requests/274

--- help.c.orig	2020-02-06 21:01:27.000000000 +0000
+++ help.c
@@ -31,9 +31,11 @@
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
@@ -976,12 +978,18 @@ void Button_Stats(int btn)
         GFX2_Log(GFX2_ERROR, "GetDiskFreeSpaceExA() failed\n");
       }
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
