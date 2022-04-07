$NetBSD: patch-nss_lib_nss_nssinit.c,v 1.1 2022/04/07 19:08:40 riastradh Exp $

Fix ctype(3) abuse: https://bugzilla.mozilla.org/show_bug.cgi?id=1246768

--- nss/lib/nss/nssinit.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/lib/nss/nssinit.c
@@ -1323,25 +1323,25 @@ NSS_VersionCheck(const char *importedVer
 #define NSS_VERSION_VARIABLE __nss_base_version
 #include "verref.h"
 
-    while (isdigit(*ptr)) {
+    while (isdigit((unsigned char)*ptr)) {
         vmajor = 10 * vmajor + *ptr - '0';
         ptr++;
     }
     if (*ptr == '.') {
         ptr++;
-        while (isdigit(*ptr)) {
+        while (isdigit((unsigned char)*ptr)) {
             vminor = 10 * vminor + *ptr - '0';
             ptr++;
         }
         if (*ptr == '.') {
             ptr++;
-            while (isdigit(*ptr)) {
+            while (isdigit((unsigned char)*ptr)) {
                 vpatch = 10 * vpatch + *ptr - '0';
                 ptr++;
             }
             if (*ptr == '.') {
                 ptr++;
-                while (isdigit(*ptr)) {
+                while (isdigit((unsigned char)*ptr)) {
                     vbuild = 10 * vbuild + *ptr - '0';
                     ptr++;
                 }
