$NetBSD: patch-go.mod,v 1.1 2026/07/05 08:40:18 drixter Exp $

Use experimental patch sqlite v1.52.1-0.20260614085003-e62c32f2abc6 for NetBSD
https://gitlab.com/cznic/sqlite/-/work_items/246#note_3456840891


--- go.mod.orig	2026-07-04 16:11:27.045574395 +0000
+++ go.mod
@@ -34,7 +34,7 @@ require (
 	google.golang.org/grpc v1.81.1
 	gopkg.in/mail.v2 v2.3.1
 	gopkg.in/yaml.v3 v3.0.1
-	modernc.org/sqlite v1.50.1
+	modernc.org/sqlite v1.52.1-0.20260614085003-e62c32f2abc6 
 )
 
 require (
@@ -97,7 +97,7 @@ require (
 	google.golang.org/genproto/googleapis/rpc v0.0.0-20260519071638-aa98bba5eb94 // indirect
 	google.golang.org/protobuf v1.36.11 // indirect
 	gopkg.in/alexcesaro/quotedprintable.v3 v3.0.0-20150716171945-2caba252f4dc // indirect
-	modernc.org/libc v1.72.3 // indirect
+	modernc.org/libc v1.73.3 // indirect
 	modernc.org/mathutil v1.7.1 // indirect
 	modernc.org/memory v1.11.0 // indirect
 )
