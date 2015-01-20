$NetBSD: patch-libxl_libxl_uuid.c,v 1.1 2015/01/20 16:42:13 bouyer Exp $

--- libxl/libxl_uuid.c.orig	2015-01-19 17:05:02.000000000 +0100
+++ libxl/libxl_uuid.c	2015-01-19 17:18:47.000000000 +0100
@@ -77,7 +77,7 @@
     assert(status == uuid_s_ok);
 }
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 int libxl_uuid_from_string(libxl_uuid *uuid, const char *in)
 {
     uint32_t status;
@@ -112,7 +112,7 @@
     memset(&uuid->uuid, 0, sizeof(uuid->uuid));
 }
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 int libxl_uuid_compare(const libxl_uuid *uuid1, const libxl_uuid *uuid2)
 {
 
