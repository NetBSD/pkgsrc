$NetBSD: patch-lib_config_optionsconfiguration.go,v 1.4 2017/02/08 21:59:28 wiz Exp $

By default, disable automatic upgrade checking, because it is a
privacy leak, of the sort that would earn a warning on f-droid a la:
  https://f-droid.org/wiki/page/Antifeature:Tracking

Not reported upstream because they appear to think upgrade
checks/web-bugs are a feature.

--- lib/config/optionsconfiguration.go.orig	2017-02-07 20:25:33.000000000 +0000
+++ lib/config/optionsconfiguration.go
@@ -117,7 +117,7 @@ type OptionsConfiguration struct {
 	URPostInsecurely        bool                    `xml:"urPostInsecurely" json:"urPostInsecurely" default:"false"` // For testing
 	URInitialDelayS         int                     `xml:"urInitialDelayS" json:"urInitialDelayS" default:"1800"`
 	RestartOnWakeup         bool                    `xml:"restartOnWakeup" json:"restartOnWakeup" default:"true"`
-	AutoUpgradeIntervalH    int                     `xml:"autoUpgradeIntervalH" json:"autoUpgradeIntervalH" default:"12"` // 0 for off
+	AutoUpgradeIntervalH    int                     `xml:"autoUpgradeIntervalH" json:"autoUpgradeIntervalH" default:"0"` // 0 for off
 	UpgradeToPreReleases    bool                    `xml:"upgradeToPreReleases" json:"upgradeToPreReleases"`              // when auto upgrades are enabled
 	KeepTemporariesH        int                     `xml:"keepTemporariesH" json:"keepTemporariesH" default:"24"`         // 0 for off
 	CacheIgnoredFiles       bool                    `xml:"cacheIgnoredFiles" json:"cacheIgnoredFiles" default:"false"`
