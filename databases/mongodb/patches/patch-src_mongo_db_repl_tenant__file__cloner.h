$NetBSD: patch-src_mongo_db_repl_tenant__file__cloner.h,v 1.1 2023/07/29 11:45:43 adam Exp $

boost::filesystem::ofstream deprected, use std::ofstream instead.

--- src/mongo/db/repl/tenant_file_cloner.h.orig	2023-07-26 18:58:00.000000000 +0000
+++ src/mongo/db/repl/tenant_file_cloner.h
@@ -30,6 +30,7 @@
 #pragma once
 
 #include <boost/filesystem.hpp>
+#include <fstream>
 #include <memory>
 #include <vector>
 
