$NetBSD: patch-web_ui_ui.go,v 1.1 2020/01/08 22:33:05 adam Exp $

Use absolute path for web files.

--- web/ui/ui.go.orig	2020-01-08 22:04:44.000000000 +0000
+++ web/ui/ui.go
@@ -27,22 +27,7 @@ import (
 
 // Assets contains the project's assets.
 var Assets http.FileSystem = func() http.FileSystem {
-	wd, err := os.Getwd()
-	if err != nil {
-		panic(err)
-	}
-	var assetsPrefix string
-	switch path.Base(wd) {
-	case "prometheus":
-		// When running Prometheus (without built-in assets) from the repo root.
-		assetsPrefix = "./web/ui"
-	case "web":
-		// When running web tests.
-		assetsPrefix = "./ui"
-	case "ui":
-		// When generating statically compiled-in assets.
-		assetsPrefix = "./"
-	}
+	var assetsPrefix string = "@WEBUI_DIR@"
 
 	static := filter.Keep(
 		http.Dir(path.Join(assetsPrefix, "static")),
