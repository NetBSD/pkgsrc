$NetBSD: patch-orc_orctarget.h,v 1.1 2019/10/14 16:26:46 adam Exp $

Add missing typedef.
https://gitlab.freedesktop.org/gstreamer/orc/issues/26

--- orc/orctarget.h.orig	2019-09-09 07:21:43.000000000 +0000
+++ orc/orctarget.h
@@ -19,7 +19,7 @@ enum {
   ORC_TARGET_FAST_DENORMAL = (1<<31)
 };
 
-enum {
+typedef enum {
   ORC_TARGET_POWERPC_64BIT = (1<<0),
   ORC_TARGET_POWERPC_LE = (1<<1),
   ORC_TARGET_POWERPC_ALTIVEC = (1<<2),
