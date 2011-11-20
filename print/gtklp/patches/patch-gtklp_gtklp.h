$NetBSD: patch-gtklp_gtklp.h,v 1.1 2011/11/20 08:29:37 sbd Exp $

With cups-1.5 <cups/ppd.h> in no-longer include by <cups/cups.h>.

--- gtklp/gtklp.h.orig	2009-06-21 12:25:37.000000000 +0000
+++ gtklp/gtklp.h
@@ -26,6 +26,7 @@
 
 #include <gtk/gtk.h>
 #include <cups/cups.h>
+#include <cups/ppd.h>
 #include <cups/http.h>
 
 #include <defaults.h>
