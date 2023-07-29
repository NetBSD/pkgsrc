$NetBSD: patch-src_mongo_util_dns__query__posix-impl.h,v 1.1 2023/07/29 11:46:45 adam Exp $

Fix for "Durations must be constructed from values of integral type that are
representable as 64-bit signed integers" from src/mongo/util/duration.h.

--- src/mongo/util/dns_query_posix-impl.h.orig	2023-07-28 07:25:45.391290555 +0000
+++ src/mongo/util/dns_query_posix-impl.h
@@ -196,7 +196,7 @@ public:
     }
 
     Seconds getTtl() const {
-        return Seconds(ns_rr_ttl(this->_resource_record));
+        return Seconds((int64_t)ns_rr_ttl(this->_resource_record));
     }
 
 private:
