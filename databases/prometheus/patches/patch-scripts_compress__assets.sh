$NetBSD: patch-scripts_compress__assets.sh,v 1.1 2026/09/26 10:58:30 tnn Exp $

Remove needless GNUism.

--- scripts/compress_assets.sh.orig	2026-08-24 12:25:43.543153159 +0000
+++ scripts/compress_assets.sh
@@ -30,6 +30,6 @@ find "${STATIC_DIR}" -type f ! -name '*.gz' -exec bash
 ' bash {} +
 
 # Append the paths of gzipped files to embed.go
-find static -type f -name '*.gz' -print0 | sort -z | xargs -0 echo //go:embed >> embed.go
+find static -type f -name '*.gz' -print | sort | xargs echo //go:embed >> embed.go
 
 echo var EmbedFS embed.FS >> embed.go
