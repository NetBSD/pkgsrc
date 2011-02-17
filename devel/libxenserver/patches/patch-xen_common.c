$NetBSD: patch-xen_common.c,v 1.1.1.1 2011/02/17 09:54:02 sborrill Exp $

--- src/xen_common.c.orig	2011-02-11 12:59:37.000000000 +0000
+++ src/xen_common.c	2011-02-11 13:00:20.000000000 +0000
@@ -1131,6 +1131,7 @@
     default:
         assert(false);
     }
+    return 0;
 }
 
 
@@ -1638,6 +1639,7 @@
     default:
         assert(false);
     }
+    return NULL;
 }
 
 
