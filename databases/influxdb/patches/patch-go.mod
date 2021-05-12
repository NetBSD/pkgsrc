$NetBSD: patch-go.mod,v 1.1 2021/05/12 09:59:22 jperkin Exp $

Replace with newer pkg/term with many fixes.

--- go.mod.orig	2021-01-27 21:39:33.000000000 +0000
+++ go.mod
@@ -9,6 +9,7 @@ require (
 	github.com/apache/arrow/go/arrow v0.0.0-20191024131854-af6fa24be0db
 	github.com/bmizerany/pat v0.0.0-20170815010413-6226ea591a40
 	github.com/boltdb/bolt v1.3.1
+	github.com/c-bata/go-prompt v0.2.2 // indirect
 	github.com/cespare/xxhash v1.1.0
 	github.com/davecgh/go-spew v1.1.1
 	github.com/dgrijalva/jwt-go v3.2.0+incompatible
@@ -28,7 +29,7 @@ require (
 	github.com/klauspost/cpuid v0.0.0-20170728055534-ae7887de9fa5 // indirect
 	github.com/klauspost/crc32 v0.0.0-20161016154125-cb6bfca970f6 // indirect
 	github.com/klauspost/pgzip v1.0.2-0.20170402124221-0bf5dcad4ada
-	github.com/mattn/go-isatty v0.0.4
+	github.com/mattn/go-isatty v0.0.12
 	github.com/mschoch/smat v0.0.0-20160514031455-90eadee771ae // indirect
 	github.com/opentracing/opentracing-go v1.0.3-0.20180606204148-bd9c31933947
 	github.com/paulbellamy/ratecounter v0.2.0
@@ -46,9 +47,12 @@ require (
 	go.uber.org/zap v1.9.1
 	golang.org/x/crypto v0.0.0-20191011191535-87dc89f01550
 	golang.org/x/sync v0.0.0-20190911185100-cd5d95a43a6e
-	golang.org/x/sys v0.0.0-20200107162124-548cf772de50
+	golang.org/x/sys v0.0.0-20200918174421-af09f7315aff
 	golang.org/x/text v0.3.2
 	golang.org/x/time v0.0.0-20190308202827-9d24e82272b4
 	gonum.org/v1/gonum v0.6.0 // indirect
 	google.golang.org/grpc v1.26.0
 )
+
+replace github.com/c-bata/go-prompt => github.com/c-bata/go-prompt v0.2.5
+replace github.com/pkg/term => github.com/pkg/term v1.1.0
