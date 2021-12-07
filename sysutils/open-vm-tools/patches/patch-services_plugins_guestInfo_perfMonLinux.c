$NetBSD: patch-services_plugins_guestInfo_perfMonLinux.c,v 1.1 2021/12/07 18:25:46 adam Exp $

uselocale() is not available in NetBSD.

--- services/plugins/guestInfo/perfMonLinux.c.orig	2021-12-07 13:15:52.237512911 +0000
+++ services/plugins/guestInfo/perfMonLinux.c
@@ -1587,7 +1587,7 @@ GuestInfoTakeSample(DynBuf *statBuf)  //
     */
    newLoc = newlocale(LC_ALL_MASK, "C", (locale_t)0);
    if (newLoc != (locale_t)0) {
-      prevLoc = uselocale(newLoc);
+      prevLoc = setlocale(LC_ALL, newLoc);
    } else {
       g_warning("%s: newlocale failed, error=%d.\n", __FUNCTION__, errno);
    }
@@ -1600,7 +1600,7 @@ GuestInfoTakeSample(DynBuf *statBuf)  //
 
    if (newLoc != (locale_t)0) {
       /* Restore thread previous locale */
-      uselocale(prevLoc);
+      setlocale(LC_ALL, prevLoc);
       freelocale(newLoc);
    }
 
