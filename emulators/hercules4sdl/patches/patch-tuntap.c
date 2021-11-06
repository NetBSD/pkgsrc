$NetBSD: patch-tuntap.c,v 1.1 2021/11/06 16:43:23 rhialto Exp $

NetBSD is not Linux. Conditionalize the compilation of Linux stuff.

--- tuntap.c.orig	2019-09-10 18:06:20.000000000 +0000
+++ tuntap.c
@@ -26,6 +26,11 @@
 /* Thus  for  preconfigured FreeBSD interfaces we need to modify the */
 /* name of the character file being opened.                          */
 
+/* On NetBSD you open /dev/tun<n> which must be given by the user,   */
+/* who has pre-configured that tunnel for use.                       */
+/* If you want a L2 (ethernet) interface, open /dev/tap or           */
+/* /dev/tap<n>.  You cannot switch from one mode to the other.       */
+
 
 #include "hstdinc.h"
 
@@ -71,6 +76,7 @@ static void tuntap_term( void* arg )
 //
 // TUNTAP_SetMode           (TUNTAP_CreateInterface helper)
 //
+#if defined(__linux__) || defined(OPTION_W32_CTCI)
 static int TUNTAP_SetMode (int fd, struct hifr *hifr, int iFlags)
 {
     int rc;
@@ -157,6 +163,7 @@ static int TUNTAP_SetMode (int fd, struc
 
     return rc;
 }   // End of function  TUNTAP_SetMode()
+#endif /* __linux__ || OPTION_W32_CTCI */
 
 
 //
@@ -248,6 +255,7 @@ int             TUNTAP_CreateInterface( 
     if ( strncasecmp( utsbuf.sysname, "linux",  5 ) == 0 )
 #endif
     {
+#if defined (__linux__) || defined(OPTION_W32_CTCI)
         // Linux kernel (builtin tun device) or Windows
         struct hifr hifr;
 
@@ -271,10 +279,18 @@ int             TUNTAP_CreateInterface( 
         }
 
         strcpy( pszNetDevName, hifr.hifr_name );
+#endif /* __linux__ || OPTION_W32_CTCI */
     }
 #if !defined( OPTION_W32_CTCI )
     else
     {
+        if ((iFlags & IFF_TUN) && !strstr(pszTUNDevice, "tun")) {
+             WRMSG( HHC00156, "W", pszTUNDevice );
+        }
+        if ((iFlags & IFF_TAP) && !strstr(pszTUNDevice, "tap")) {
+             WRMSG( HHC00157, "W", pszTUNDevice );
+        }
+
         // Other OS: Simply use basename of the device
         // Notes: (JAP) This is problematic at best. Until we have a
         //        clean FreeBSD compile from the base tree I can't
