$NetBSD: patch-tools_libxl_libxl_uuid.c,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/libxl/libxl_uuid.c.orig	2016-12-05 13:03:27.000000000 +0100
+++ tools/libxl/libxl_uuid.c	2017-03-24 18:15:58.000000000 +0100
@@ -82,7 +82,7 @@
     uuid_enc_be(uuid->uuid, &nat_uuid);
 }
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 int libxl_uuid_from_string(libxl_uuid *uuid, const char *in)
 {
     uint32_t status;
@@ -120,7 +120,7 @@
     memset(&uuid->uuid, 0, sizeof(uuid->uuid));
 }
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 int libxl_uuid_compare(const libxl_uuid *uuid1, const libxl_uuid *uuid2)
 {
     uuid_t nat_uuid1, nat_uuid2;
