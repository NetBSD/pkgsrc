$NetBSD: patch-lib_zip__dirent.c,v 1.1 2015/03/26 09:30:01 wiz Exp $

Based on:
# HG changeset patch
# User Thomas Klausner <tk@giga.or.at>
# Date 1426937322 -3600
#      Sat Mar 21 12:28:42 2015 +0100
# Node ID 9f11d54f692edc152afef04178cdf16f906a21b4
# Parent  fa78ab51417f2fbf19586195dc3662497a5d790d
Avoid integer overflow. Addresses CVE-2015-2331.

Fixed similarly to patch used in PHP copy of libzip:
https://github.com/php/php-src/commit/ef8fc4b53d92fbfcd8ef1abbd6f2f5fe2c4a11e5

Thanks to Emmanuel Law <emmanuel.law@gmail.com> for the notification
about the bug.

--- lib/zip_dirent.c.orig	2013-11-28 16:57:10.000000000 +0000
+++ lib/zip_dirent.c
@@ -110,7 +110,7 @@ _zip_cdir_new(zip_uint64_t nentry, struc
 
     if (nentry == 0)
 	cd->entry = NULL;
-    else if ((cd->entry=(struct zip_entry *)malloc(sizeof(*(cd->entry))*(size_t)nentry)) == NULL) {
+    else if ((nentry > SIZE_MAX/sizeof(*(cd->entry))) || (cd->entry=(struct zip_entry *)malloc(sizeof(*(cd->entry))*(size_t)nentry)) == NULL) {
 	_zip_error_set(error, ZIP_ER_MEMORY, 0);
 	free(cd);
 	return NULL;
