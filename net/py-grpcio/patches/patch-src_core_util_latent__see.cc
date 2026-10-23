$NetBSD: patch-src_core_util_latent__see.cc,v 1.3 2026/10/23 11:35:43 ryoon Exp $

* Fix fingerprint mismatch that causes build failure.

--- src/core/util/latent_see.cc.orig	2026-10-23 11:26:52.711217091 +0000
+++ src/core/util/latent_see.cc
@@ -186,7 +186,7 @@ void Collect(Notification* n, absl::Duration timeout, 
             {earliest_timestamp, event.timestamp_begin, event.timestamp_end});
       } else {
         earliest_timestamp =
-            std::min(earliest_timestamp, abs(event.timestamp_end));
+            std::min(earliest_timestamp, std::abs(event.timestamp_end));
       }
     }
   }
