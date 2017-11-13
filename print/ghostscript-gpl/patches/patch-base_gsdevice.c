$NetBSD: patch-base_gsdevice.c,v 1.1 2017/11/13 16:41:48 he Exp $

Apply fix for CVE-2016-7978,
fixing bug 697179, fixing a double free and memory corruption.

--- base/gsdevice.c.orig	2012-08-08 08:01:36.000000000 +0000
+++ base/gsdevice.c
@@ -540,6 +540,7 @@ gx_device_init(gx_device * dev, const gx
     dev->memory = mem;
     dev->retained = !internal;
     rc_init(dev, mem, (internal ? 0 : 1));
+    rc_increment(dev->icc_struct);
 }
 
 /* Make a null device. */
