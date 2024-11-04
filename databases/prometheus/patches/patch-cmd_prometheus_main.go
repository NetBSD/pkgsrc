$NetBSD: patch-cmd_prometheus_main.go,v 1.5 2024/11/04 18:21:51 wiz Exp $

Add prefix for SYSCONFDIR and VARBASE to store configuration file and metrics data at the correct location.

--- cmd/prometheus/main.go.orig	2024-10-22 10:53:52.000000000 +0000
+++ cmd/prometheus/main.go
@@ -300,7 +300,7 @@ func main() {
 	a.HelpFlag.Short('h')
 
 	a.Flag("config.file", "Prometheus configuration file path.").
-		Default("prometheus.yml").StringVar(&cfg.configFile)
+		Default("@PKG_SYSCONFDIR@/prometheus.yml").StringVar(&cfg.configFile)
 
 	a.Flag("web.listen-address", "Address to listen on for UI, API, and telemetry. Can be repeated.").
 		Default("0.0.0.0:9090").StringsVar(&cfg.web.ListenAddresses)
@@ -347,10 +347,10 @@ func main() {
 		Default(supportedRemoteWriteProtoMsgs.Strings()...).SetValue(rwProtoMsgFlagValue(&cfg.web.AcceptRemoteWriteProtoMsgs))
 
 	a.Flag("web.console.templates", "Path to the console template directory, available at /consoles.").
-		Default("consoles").StringVar(&cfg.web.ConsoleTemplatesPath)
+		Default("@PKG_SYSCONFDIR@/consoles").StringVar(&cfg.web.ConsoleTemplatesPath)
 
 	a.Flag("web.console.libraries", "Path to the console library directory.").
-		Default("console_libraries").StringVar(&cfg.web.ConsoleLibrariesPath)
+		Default("@PKG_SYSCONFDIR@/console_libraries").StringVar(&cfg.web.ConsoleLibrariesPath)
 
 	a.Flag("web.page-title", "Document title of Prometheus instance.").
 		Default("Prometheus Time Series Collection and Processing Server").StringVar(&cfg.web.PageTitle)
@@ -359,7 +359,7 @@ func main() {
 		Default(".*").StringVar(&cfg.corsRegexString)
 
 	serverOnlyFlag(a, "storage.tsdb.path", "Base path for metrics storage.").
-		Default("data/").StringVar(&cfg.serverStoragePath)
+		Default("@VARBASE@/lib/prometheus/data/").StringVar(&cfg.serverStoragePath)
 
 	serverOnlyFlag(a, "storage.tsdb.min-block-duration", "Minimum duration of a data block before being persisted. For use in testing.").
 		Hidden().Default("2h").SetValue(&cfg.tsdb.MinBlockDuration)
