$NetBSD: patch-external_partio__zip_zip__manager.hpp,v 1.1 2023/12/22 20:53:49 prlw1 Exp $

std::unique_ptr is in <memory>
https://github.com/SuperTux/supertux/commit/81809dd5e6f611b1d64d952f6d96310bcc9c5fca

--- external/partio_zip/zip_manager.hpp.orig	2023-12-22 19:58:14.529270276 +0000
+++ external/partio_zip/zip_manager.hpp
@@ -1,8 +1,12 @@
 // SOURCE: https://github.com/wdas/partio/blob/main/src/lib/io/ZIP.h
+// NOTE: This file was edited for purposes of compatibility with SuperTux.
 
-/*
+// This include has been added to fix a problem with GCC 11+ (and maybe 10)
+#include <memory>
+
+// =============================================================================
 
-NOTE: This file was edited for purposes of compatibility with SuperTux.
+/*
 
 PARTIO SOFTWARE
 Copyright 2010 Disney Enterprises, Inc. All rights reserved
