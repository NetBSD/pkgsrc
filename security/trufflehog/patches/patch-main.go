$NetBSD: patch-main.go,v 1.2 2022/09/02 19:28:16 leot Exp $

Disable update functionality.

This avoid to patch overseer in order to add support for more operating
system and all the logic is not desiderable for a package system too.

--- main.go.orig	2022-09-02 19:00:02.000000000 +0000
+++ main.go
@@ -9,12 +9,10 @@ import (
 	"runtime"
 	"strconv"
 	"strings"
-	"syscall"
 	"time"
 
 	"github.com/felixge/fgprof"
 	"github.com/gorilla/mux"
-	"github.com/jpillora/overseer"
 	"github.com/sirupsen/logrus"
 	"gopkg.in/alecthomas/kingpin.v2"
 
@@ -25,7 +23,6 @@ import (
 	"github.com/trufflesecurity/trufflehog/v3/pkg/output"
 	"github.com/trufflesecurity/trufflehog/v3/pkg/sources"
 	"github.com/trufflesecurity/trufflehog/v3/pkg/sources/git"
-	"github.com/trufflesecurity/trufflehog/v3/pkg/updater"
 	"github.com/trufflesecurity/trufflehog/v3/pkg/version"
 )
 
@@ -118,28 +115,10 @@ func init() {
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
