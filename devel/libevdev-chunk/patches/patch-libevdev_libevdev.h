$NetBSD: patch-libevdev_libevdev.h,v 1.1 2026/04/13 15:36:31 kikadf Exp $

* Add missing functions

--- libevdev/libevdev.h.orig	2023-11-11 14:32:38.000000000 +0000
+++ libevdev/libevdev.h
@@ -29,8 +29,11 @@
 #ifdef __cplusplus
 extern "C" {
 #endif
+extern int libevdev_event_type_get_max(unsigned int type);
+extern int libevdev_event_type_from_name(const char *name);
 extern int libevdev_event_code_from_name(unsigned int type, const char *name);
 extern const char * libevdev_event_code_get_name(unsigned int type, unsigned int code);
+extern int libevdev_property_from_name(const char *name);
 #ifdef __cplusplus
 }
 #endif
