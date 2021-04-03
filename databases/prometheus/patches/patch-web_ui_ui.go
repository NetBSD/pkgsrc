$NetBSD: patch-web_ui_ui.go,v 1.3 2021/04/03 18:41:31 tnn Exp $

Use absolute path for web files.

--- web/ui/ui.go.orig	2021-03-31 10:12:23.000000000 +0000
+++ web/ui/ui.go
@@ -19,7 +19,6 @@ import (
 	"net/http"
 	"os"
 	"path"
-	"path/filepath"
 	"strings"
 
 	"github.com/shurcooL/httpfs/filter"
@@ -28,22 +27,7 @@ import (
 
 // Assets contains the project's assets.
 var Assets = func() http.FileSystem {
-	wd, err := os.Getwd()
-	if err != nil {
-		panic(err)
-	}
-	var assetsPrefix string
-	switch filepath.Base(wd) {
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
