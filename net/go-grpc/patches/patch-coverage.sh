$NetBSD: patch-coverage.sh,v 1.1 2016/09/14 21:53:17 wiz Exp $

--- coverage.sh.orig	2016-09-14 21:51:03.427200228 +0000
+++ coverage.sh
@@ -12,7 +12,7 @@ generate_cover_data() {
     mkdir "$workdir"
 
     for pkg in "$@"; do
-        if [ $pkg == "google.golang.org/grpc" -o $pkg == "google.golang.org/grpc/transport" -o $pkg == "google.golang.org/grpc/metadata" -o $pkg == "google.golang.org/grpc/credentials" ]
+        if [ $pkg = "google.golang.org/grpc" -o $pkg = "google.golang.org/grpc/transport" -o $pkg = "google.golang.org/grpc/metadata" -o $pkg = "google.golang.org/grpc/credentials" ]
             then
                 f="$workdir/$(echo $pkg | tr / -)"
                 go test -covermode="$mode" -coverprofile="$f.cover" "$pkg"
