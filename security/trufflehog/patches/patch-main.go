$NetBSD: patch-main.go,v 1.1 2022/08/07 22:21:38 leot Exp $

Disable update functionality.

This avoid to patch overseer in order to add support for more operating
system and all the logic is not desiderable for a package system too.

--- main.go.orig	2022-07-20 17:35:24.000000000 +0000
+++ main.go
@@ -10,14 +10,11 @@ import (
 	"runtime"
 	"strconv"
 	"strings"
-	"syscall"
 	"time"
 
 	"github.com/felixge/fgprof"
 	"github.com/gorilla/mux"
-	"github.com/jpillora/overseer"
 	"github.com/sirupsen/logrus"
-	"github.com/trufflesecurity/trufflehog/v3/pkg/updater"
 	"github.com/trufflesecurity/trufflehog/v3/pkg/version"
 	"gopkg.in/alecthomas/kingpin.v2"
 
@@ -117,28 +114,10 @@ func init() {
 }
 
 func main() {
-	updateCfg := overseer.Config{
-		Program:       run,
-		Debug:         *debug,
-		RestartSignal: syscall.SIGTERM,
-		// TODO: Eventually add a PreUpgrade func for signature check w/ x509 PKCS1v15
-		// PreUpgrade: checkUpdateSignature(binaryPath string),
-	}
-
-	if !*noUpdate {
-		updateCfg.Fetcher = updater.Fetcher(version.BuildVersion)
-	}
-	if version.BuildVersion == "dev" {
-		updateCfg.Fetcher = nil
-	}
-
-	err := overseer.RunErr(updateCfg)
-	if err != nil {
-		logrus.WithError(err).Fatal("error occured with trufflehog updater 🐷")
-	}
+	run()
 }
 
-func run(state overseer.State) {
+func run() {
 	if *debug {
 		fmt.Println("trufflehog " + version.BuildVersion)
 	}
