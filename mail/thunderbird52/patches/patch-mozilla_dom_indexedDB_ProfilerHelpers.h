$NetBSD: patch-mozilla_dom_indexedDB_ProfilerHelpers.h,v 1.1 2021/06/17 11:01:19 nia Exp $

Avoid macro conflict with NSS 3.66
https://bugzilla.mozilla.org/show_bug.cgi?id=1714311

--- mozilla/dom/indexedDB/ProfilerHelpers.h.orig	2018-07-09 19:54:35.000000000 +0000
+++ mozilla/dom/indexedDB/ProfilerHelpers.h
@@ -129,7 +129,7 @@ public:
       case IDBTransaction::READ_WRITE_FLUSH:
         AppendLiteral("\"readwriteflush\"");
         break;
-      case IDBTransaction::CLEANUP:
+      case IDBTransaction::TRANSACTION_CLEANUP:
         AppendLiteral("\"cleanup\"");
         break;
       case IDBTransaction::VERSION_CHANGE:
