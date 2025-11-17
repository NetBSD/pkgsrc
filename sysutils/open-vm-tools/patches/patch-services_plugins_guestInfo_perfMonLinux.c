$NetBSD: patch-services_plugins_guestInfo_perfMonLinux.c,v 1.2 2025/11/17 17:38:39 adam Exp $

uselocale() is not available in NetBSD.

--- services/plugins/guestInfo/perfMonLinux.c.orig	2025-09-18 01:06:27.000000000 +0000
+++ services/plugins/guestInfo/perfMonLinux.c
@@ -1587,7 +1587,7 @@ GuestInfoTakeSample(DynBuf *statBuf)  //
     */
    newLoc = newlocale(LC_ALL_MASK, "C", (locale_t)0);
    if (newLoc != (locale_t)0) {
-      prevLoc = uselocale(newLoc);
+      prevLoc = (locale_t)setlocale(LC_ALL, (const char *)newLoc);
    } else {
       g_warning("%s: newlocale failed, error=%d.\n", __FUNCTION__, errno);
    }
@@ -1600,7 +1600,7 @@ GuestInfoTakeSample(DynBuf *statBuf)  //
 
    if (newLoc != (locale_t)0) {
       /* Restore thread previous locale */
-      uselocale(prevLoc);
+      setlocale(LC_ALL, (const char *)prevLoc);
       freelocale(newLoc);
    }
 
