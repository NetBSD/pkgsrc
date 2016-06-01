$NetBSD: patch-lib_config_optionsconfiguration.go,v 1.3 2016/06/01 18:46:01 gdt Exp $

By default, disable automatic upgrade checking, because it is a
privacy leak, of the sort that would earn a warning on f-droid a la:
  https://f-droid.org/wiki/page/Antifeature:Tracking

Not reported upstream because they appear to think upgrade
checks/web-bugs are a feature.

--- lib/config/optionsconfiguration.go.orig	2016-05-26 09:16:08.000000000 +0000
+++ lib/config/optionsconfiguration.go
@@ -29,7 +29,7 @@ type OptionsConfiguration struct {
 	URPostInsecurely        bool     `xml:"urPostInsecurely" json:"urPostInsecurely" default:"false"` // For testing
 	URInitialDelayS         int      `xml:"urInitialDelayS" json:"urInitialDelayS" default:"1800"`
 	RestartOnWakeup         bool     `xml:"restartOnWakeup" json:"restartOnWakeup" default:"true"`
-	AutoUpgradeIntervalH    int      `xml:"autoUpgradeIntervalH" json:"autoUpgradeIntervalH" default:"12"` // 0 for off
+	AutoUpgradeIntervalH    int      `xml:"autoUpgradeIntervalH" json:"autoUpgradeIntervalH" default:"0"` // 0 for off
 	KeepTemporariesH        int      `xml:"keepTemporariesH" json:"keepTemporariesH" default:"24"`         // 0 for off
 	CacheIgnoredFiles       bool     `xml:"cacheIgnoredFiles" json:"cacheIgnoredFiles" default:"false"`
 	ProgressUpdateIntervalS int      `xml:"progressUpdateIntervalS" json:"progressUpdateIntervalS" default:"5"`
