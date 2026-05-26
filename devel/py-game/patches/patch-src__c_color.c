$NetBSD: patch-src__c_color.c,v 1.1 2026/05/26 02:13:09 gutteridge Exp $

Fix ctype(3) usage.

--- src_c/color.c.orig	2024-09-29 12:15:28.004111800 +0000
+++ src_c/color.c
@@ -335,7 +335,7 @@ _hextoint(char *hex, Uint8 *val)
      */
     Uint8 temp = 0;
 
-    switch (toupper(hex[0])) {
+    switch (toupper((unsigned char)hex[0])) {
         case '0':
             break;
         case '1':
@@ -387,7 +387,7 @@ _hextoint(char *hex, Uint8 *val)
             return 0;
     }
 
-    switch (toupper(hex[1])) {
+    switch (toupper((unsigned char)hex[1])) {
         case '0':
             break;
         case '1':
