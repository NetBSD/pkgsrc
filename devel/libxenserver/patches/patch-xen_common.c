$NetBSD: patch-xen_common.c,v 1.2 2013/07/18 11:59:28 sborrill Exp $

--- src/xen_common.c.orig	2013-06-14 14:51:06.000000000 +0100
+++ src/xen_common.c	2013-07-18 12:52:57.000000000 +0100
@@ -1310,6 +1310,7 @@
     default:
         assert(false);
     }
+    return 0;
 }
 
 
@@ -1826,6 +1827,7 @@
             assert(false);
             break;
     }
+    return NULL;
 }
 
 
