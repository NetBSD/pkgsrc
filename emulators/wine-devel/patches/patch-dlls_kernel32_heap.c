$NetBSD: patch-dlls_kernel32_heap.c,v 1.1 2012/05/23 17:48:54 marino Exp $

--- dlls/kernel32/heap.c.orig	2011-08-05 17:24:22.000000000 +0000
+++ dlls/kernel32/heap.c
@@ -1146,7 +1146,8 @@ BOOL WINAPI GlobalMemoryStatusEx( LPMEMO
     SYSTEM_INFO si;
 #ifdef linux
     FILE *f;
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
+   || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
     unsigned long val;
     int mib[2];
     size_t size_sys;
@@ -1218,7 +1219,9 @@ BOOL WINAPI GlobalMemoryStatusEx( LPMEMO
         }
         fclose( f );
     }
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
+   || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__) \
+   || defined(__DragonFly__)
     mib[0] = CTL_HW;
     mib[1] = HW_PHYSMEM;
     size_sys = sizeof(val);
