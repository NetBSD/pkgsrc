$NetBSD: patch-gflags_src_gflags.cc,v 1.1 2013/05/09 20:06:09 joerg Exp $

--- gflags/src/gflags.cc.orig	2013-05-03 18:22:10.000000000 +0000
+++ gflags/src/gflags.cc
@@ -358,13 +358,13 @@ string FlagValue::ToString() const {
     case FV_BOOL:
       return VALUE_AS(bool) ? "true" : "false";
     case FV_INT32:
-      snprintf(intbuf, sizeof(intbuf), "%"PRId32, VALUE_AS(int32));
+      snprintf(intbuf, sizeof(intbuf), "%" PRId32, VALUE_AS(int32));
       return intbuf;
     case FV_INT64:
-      snprintf(intbuf, sizeof(intbuf), "%"PRId64, VALUE_AS(int64));
+      snprintf(intbuf, sizeof(intbuf), "%" PRId64, VALUE_AS(int64));
       return intbuf;
     case FV_UINT64:
-      snprintf(intbuf, sizeof(intbuf), "%"PRIu64, VALUE_AS(uint64));
+      snprintf(intbuf, sizeof(intbuf), "%" PRIu64, VALUE_AS(uint64));
       return intbuf;
     case FV_DOUBLE:
       snprintf(intbuf, sizeof(intbuf), "%.17g", VALUE_AS(double));
