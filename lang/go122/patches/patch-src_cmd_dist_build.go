$NetBSD: patch-src_cmd_dist_build.go,v 1.1 2024/02/09 20:34:10 bsiegert Exp $

Build with debugging symbols and paths built in. Otherwise, the go tool
needs /proc mounted to find its goroot directory.

--- src/cmd/dist/build.go.orig	2023-11-29 21:21:46.000000000 +0000
+++ src/cmd/dist/build.go
@@ -1317,14 +1317,6 @@ func toolenv() []string {
 		// as the original build system.
 		env = append(env, "CGO_ENABLED=0")
 	}
-	if isRelease || os.Getenv("GO_BUILDER_NAME") != "" {
-		// Add -trimpath for reproducible builds of releases.
-		// Include builders so that -trimpath is well-tested ahead of releases.
-		// Do not include local development, so that people working in the
-		// main branch for day-to-day work on the Go toolchain itself can
-		// still have full paths for stack traces for compiler crashes and the like.
-		env = append(env, "GOFLAGS=-trimpath -ldflags=-w -gcflags=cmd/...=-dwarf=false")
-	}
 	return env
 }
 
