$NetBSD: patch-src_mongo_db_repl_oplog__fetcher.cpp,v 1.1 2019/06/28 16:30:56 gdt Exp $

Fix build w/ boost >= 1.66

--- src/mongo/db/repl/oplog_fetcher.cpp.orig	2018-08-29 14:02:00.126096548 +0000
+++ src/mongo/db/repl/oplog_fetcher.cpp
@@ -265,7 +265,7 @@ StatusWith<boost::optional<rpc::OplogQue
         if (!metadataResult.isOK()) {
             return metadataResult.getStatus();
         }
-        oqMetadata = boost::make_optional<rpc::OplogQueryMetadata>(metadataResult.getValue());
+        oqMetadata = boost::make_optional(metadataResult.getValue());
     }
     return oqMetadata;
 }
