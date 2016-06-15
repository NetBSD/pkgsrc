$NetBSD: patch-include_hid.h,v 1.1 2016/06/15 18:38:07 rumko Exp $

malloc and friends need stdlib

--- include/hid.h.orig	2007-02-28 03:22:44.000000000 +0000
+++ include/hid.h
@@ -2,6 +2,7 @@
 #define __INCLUDED_HID_H__
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <usb.h>
 #include <hidparser.h>
 
