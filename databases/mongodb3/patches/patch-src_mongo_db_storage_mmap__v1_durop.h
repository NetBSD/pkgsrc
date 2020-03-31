$NetBSD: patch-src_mongo_db_storage_mmap__v1_durop.h,v 1.3 2020/03/31 14:34:41 gdt Exp $

This file uses std::shared_ptr, but did not include the memory header as required.

Filed upstream as ttps://jira.mongodb.org/browse/SERVER-47172

--- src/mongo/db/storage/mmap_v1/durop.h.orig	2020-01-08 16:30:41.000000000 +0000
+++ src/mongo/db/storage/mmap_v1/durop.h
@@ -30,6 +30,7 @@
 
 #pragma once
 
+#include <memory>
 
 #include "mongo/db/storage/mmap_v1/dur_journalformat.h"
 #include "mongo/db/storage/paths.h"
