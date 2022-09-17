$NetBSD: patch-go.mod,v 1.1 2022/09/17 11:54:43 bsiegert Exp $

Update quic-go to a version that works with Go 1.19

--- go.mod.orig	2022-09-17 10:30:31.196446171 +0000
+++ go.mod
@@ -30,7 +30,7 @@ require (
 	github.com/kballard/go-shellquote v0.0.0-20180428030007-95032a82bc51
 	github.com/klauspost/cpuid/v2 v2.0.9 // indirect
 	github.com/lib/pq v1.10.3
-	github.com/lucas-clemente/quic-go v0.27.0
+	github.com/lucas-clemente/quic-go v0.28.1
 	github.com/maruel/panicparse v1.6.1
 	github.com/maxbrunsfeld/counterfeiter/v6 v6.3.0
 	github.com/minio/sha256-simd v1.0.0
@@ -51,8 +51,8 @@ require (
 	github.com/vitrun/qart v0.0.0-20160531060029-bf64b92db6b0
 	golang.org/x/crypto v0.0.0-20210921155107-089bfa567519
 	golang.org/x/mod v0.5.1 // indirect
-	golang.org/x/net v0.0.0-20210924151903-3ad01bbaa167
-	golang.org/x/sys v0.0.0-20220114195835-da31bd327af9
+	golang.org/x/net v0.0.0-20220624214902-1bab6f366d9e
+	golang.org/x/sys v0.0.0-20220520151302-bc2c85ada10a
 	golang.org/x/text v0.3.7
 	golang.org/x/time v0.0.0-20210723032227-1f47c861a9ac
 	golang.org/x/tools v0.1.7
@@ -67,8 +67,9 @@ require (
 	github.com/go-task/slim-sprig v0.0.0-20210107165309-348f09dbbbc0 // indirect
 	github.com/golang/protobuf v1.5.2 // indirect
 	github.com/marten-seemann/qtls-go1-16 v0.1.5 // indirect
-	github.com/marten-seemann/qtls-go1-17 v0.1.1 // indirect
-	github.com/marten-seemann/qtls-go1-18 v0.1.1 // indirect
+	github.com/marten-seemann/qtls-go1-17 v0.1.2 // indirect
+	github.com/marten-seemann/qtls-go1-18 v0.1.2 // indirect
+	github.com/marten-seemann/qtls-go1-19 v0.1.0-beta.1 // indirect
 	github.com/matttproud/golang_protobuf_extensions v1.0.1 // indirect
 	github.com/nxadm/tail v1.4.8 // indirect
 	github.com/onsi/ginkgo v1.16.4 // indirect
