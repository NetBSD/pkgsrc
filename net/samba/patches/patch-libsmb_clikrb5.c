$NetBSD: patch-libsmb_clikrb5.c,v 1.1 2011/07/27 04:05:10 taca Exp $

* KRB5_DEPRECATED would not be defined as boolean 0 or 1.

--- libsmb/clikrb5.c.orig	2009-09-30 12:21:56.000000000 +0000
+++ libsmb/clikrb5.c
@@ -22,7 +22,7 @@
 */
 
 #define KRB5_PRIVATE    1       /* this file uses PRIVATE interfaces! */
-#define KRB5_DEPRECATED 1       /* this file uses DEPRECATED interfaces! */
+#define KRB5_DEPRECATED        /* this file uses DEPRECATED interfaces! */
 
 #include "includes.h"
 
