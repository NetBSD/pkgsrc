$NetBSD: patch-main.go,v 1.4 2024/01/07 13:10:55 leot Exp $

Disable update functionality.

This avoid to patch overseer in order to add support for more operating
systems and all the logic is not desiderable for a package system too.

--- main.go.orig	2023-12-23 06:45:27.000000000 +0000
+++ main.go
@@ -15,7 +15,6 @@ import (
 	"github.com/alecthomas/kingpin/v2"
 	"github.com/felixge/fgprof"
 	"github.com/go-logr/logr"
-	"github.com/jpillora/overseer"
 	"github.com/mattn/go-isatty"
 	"google.golang.org/protobuf/types/known/anypb"
 
@@ -32,7 +31,6 @@ import (
 	"github.com/trufflesecurity/trufflehog/v3/pkg/pb/sourcespb"
 	"github.com/trufflesecurity/trufflehog/v3/pkg/sources"
 	"github.com/trufflesecurity/trufflehog/v3/pkg/tui"
-	"github.com/trufflesecurity/trufflehog/v3/pkg/updater"
 	"github.com/trufflesecurity/trufflehog/v3/pkg/version"
 )
 
@@ -42,7 +40,6 @@ var (
 	debug               = cli.Flag("debug", "Run in debug mode.").Bool()
 	trace               = cli.Flag("trace", "Run in trace mode.").Bool()
 	profile             = cli.Flag("profile", "Enables profiling and sets a pprof and fgprof server on :18066.").Bool()
-	localDev            = cli.Flag("local-dev", "Hidden feature to disable overseer for local dev.").Hidden().Bool()
 	jsonOut             = cli.Flag("json", "Output in JSON format.").Short('j').Bool()
 	jsonLegacy          = cli.Flag("json-legacy", "Use the pre-v3.0 JSON format. Only works with git, gitlab, and github sources.").Bool()
 	gitHubActionsFormat = cli.Flag("github-actions", "Output in GitHub Actions format.").Bool()
@@ -191,36 +188,12 @@ func main() {
 	// make it the default logger for contexts
 	context.SetDefaultLogger(logger)
 
-	if *localDev {
-		run(overseer.State{})
-		os.Exit(0)
-	}
-
 	defer func() { _ = sync() }()
-	logFatal := logFatalFunc(logger)
-
-	updateCfg := overseer.Config{
-		Program:       run,
-		Debug:         *debug,
-		RestartSignal: syscall.SIGTERM,
-		// TODO: Eventually add a PreUpgrade func for signature check w/ x509 PKCS1v15
-		// PreUpgrade: checkUpdateSignature(binaryPath string),
-	}
 
-	if !*noUpdate {
-		updateCfg.Fetcher = updater.Fetcher(version.BuildVersion)
-	}
-	if version.BuildVersion == "dev" {
-		updateCfg.Fetcher = nil
-	}
-
-	err := overseer.RunErr(updateCfg)
-	if err != nil {
-		logFatal(err, "error occurred with trufflehog updater 🐷")
-	}
+	run()
 }
 
-func run(state overseer.State) {
+func run() {
 	ctx, cancel := context.WithCancelCause(context.Background())
 	defer cancel(nil)
 
