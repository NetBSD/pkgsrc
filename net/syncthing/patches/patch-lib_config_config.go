$NetBSD: patch-lib_config_config.go,v 1.1 2015/10/03 16:26:00 tnn Exp $

Disable auto upgrade mechanism. It would overwrite the binary in /usr/pkg/bin
with something the user doesn't necessarily trust.

--- lib/config/config.go.orig	2015-08-16 13:29:48.000000000 +0000
+++ lib/config/config.go
@@ -229,7 +229,7 @@ type OptionsConfiguration struct {
 	URAccepted              int      `xml:"urAccepted" json:"urAccepted"` // Accepted usage reporting version; 0 for off (undecided), -1 for off (permanently)
 	URUniqueID              string   `xml:"urUniqueID" json:"urUniqueId"` // Unique ID for reporting purposes, regenerated when UR is turned on.
 	RestartOnWakeup         bool     `xml:"restartOnWakeup" json:"restartOnWakeup" default:"true"`
-	AutoUpgradeIntervalH    int      `xml:"autoUpgradeIntervalH" json:"autoUpgradeIntervalH" default:"12"` // 0 for off
+	AutoUpgradeIntervalH    int      `xml:"autoUpgradeIntervalH" json:"autoUpgradeIntervalH" default:"0"` // 0 for off
 	KeepTemporariesH        int      `xml:"keepTemporariesH" json:"keepTemporariesH" default:"24"`         // 0 for off
 	CacheIgnoredFiles       bool     `xml:"cacheIgnoredFiles" json:"cacheIgnoredFiles" default:"true"`
 	ProgressUpdateIntervalS int      `xml:"progressUpdateIntervalS" json:"progressUpdateIntervalS" default:"5"`
