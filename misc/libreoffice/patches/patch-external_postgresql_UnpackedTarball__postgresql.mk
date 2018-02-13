$NetBSD: patch-external_postgresql_UnpackedTarball__postgresql.mk,v 1.1 2018/02/13 13:03:07 ryoon Exp $

--- external/postgresql/UnpackedTarball_postgresql.mk.orig	2018-02-08 14:35:19.000000000 +0000
+++ external/postgresql/UnpackedTarball_postgresql.mk
@@ -17,6 +17,7 @@ $(eval $(call gb_UnpackedTarball_add_pat
 	external/postgresql/postgresql-libs-leak.patch \
 	external/postgresql/postgresql-9.2.1-autoreconf.patch \
 	external/postgresql/postgresql-9.2.1-libreoffice.patch \
+	external/postgresql/postgresql-9.2.1-openssl-1.1.patch \
 ))
 
 ifeq ($(SYSTEM_ZLIB),)
