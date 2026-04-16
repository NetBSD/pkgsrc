$NetBSD: patch-src_core_util_latent__see.cc,v 1.1 2026/04/16 09:58:01 adam Exp $

Fix build on NetBSD.

--- src/core/util/latent_see.cc.orig	2026-03-24 23:06:54.000000000 +0000
+++ src/core/util/latent_see.cc
@@ -186,7 +186,11 @@ void Collect(Notification* n, absl::Duration timeout, 
             {earliest_timestamp, event.timestamp_begin, event.timestamp_end});
       } else {
         earliest_timestamp =
+#ifdef __NetBSD__
+            std::min(static_cast<int>(earliest_timestamp), abs(event.timestamp_end));
+#else
             std::min(earliest_timestamp, abs(event.timestamp_end));
+#endif
       }
     }
   }
