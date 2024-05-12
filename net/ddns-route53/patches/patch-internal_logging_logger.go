$NetBSD: patch-internal_logging_logger.go,v 1.1 2024/05/12 12:41:58 pho Exp $

Do not include timestamp in log messages. We expect them to be sent to
syslogd(8) and duplicate timestamps aren't helpful.

--- internal/logging/logger.go.orig	2024-03-24 14:52:52.000000000 +0000
+++ internal/logging/logger.go
@@ -3,7 +3,6 @@ package logging
 import (
 	"io"
 	"os"
-	"time"
 
 	"github.com/crazy-max/ddns-route53/v2/internal/config"
 	"github.com/rs/zerolog"
@@ -22,7 +21,7 @@ func Configure(cli config.Cli) {
 		w = zerolog.ConsoleWriter{
 			Out:        os.Stdout,
 			NoColor:    noColor || cli.LogNoColor,
-			TimeFormat: time.RFC1123,
+			PartsExclude: []string{"time"},
 		}
 	} else {
 		w = os.Stdout
