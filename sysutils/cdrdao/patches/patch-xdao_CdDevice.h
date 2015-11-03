$NetBSD: patch-xdao_CdDevice.h,v 1.1 2015/11/03 19:08:45 joerg Exp $

--- xdao/CdDevice.h.orig	2015-11-03 11:23:29.000000000 +0000
+++ xdao/CdDevice.h
@@ -20,7 +20,6 @@
 #ifndef __CD_DEVICE_H__
 #define __CD_DEVICE_H__
 
-#include <sigc++/object.h>
 #include <gdk/gdk.h>
 #include <string>
 
