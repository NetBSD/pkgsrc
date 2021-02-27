$NetBSD: patch-protobuf_protobuf.gyp,v 1.7 2021/02/27 04:19:46 ryoon Exp $

* Pass LDFLAGS from pkgsrc.
  Fix -lprotobuf is not found error.

--- protobuf/protobuf.gyp.orig	2021-02-15 05:04:33.000000000 +0000
+++ protobuf/protobuf.gyp
@@ -156,6 +156,9 @@
             'libraries': [
               '-lprotobuf',
             ],
+            'ldflags': [
+              '<!(echo $LDFLAGS)',
+            ],
           },
         },
         {  # else
