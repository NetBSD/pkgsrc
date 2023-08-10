$NetBSD: patch-go.mod,v 1.1 2023/08/10 18:15:01 sjmulder Exp $

Patched version of 'beeep' with fixes for Illumos.

--- go.mod.orig	2023-01-26 17:42:48.000000000 +0000
+++ go.mod
@@ -7,13 +7,13 @@ require (
 	github.com/adrg/xdg v0.4.0
 	github.com/atotto/clipboard v0.1.4
 	github.com/gdamore/tcell/v2 v2.5.4
-	github.com/gen2brain/beeep v0.0.0-20220909211152-5a9ec94374f6
 	github.com/gobwas/glob v0.2.3
 	github.com/icza/gox v0.0.0-20230117093757-93f961aa2755
 	github.com/microcosm-cc/bluemonday v1.0.21
 	github.com/pelletier/go-toml/v2 v2.0.6
 	github.com/rivo/tview v0.0.0-20230104153304-892d1a2eb0da
 	github.com/rivo/uniseg v0.4.3
+	github.com/sjmulder/beeep v0.0.0-20230810161728-20d8a311bc17
 	github.com/spf13/pflag v1.0.5
 	golang.org/x/exp v0.0.0-20230125214544-b3c2aaf6208d
 	golang.org/x/net v0.5.0
@@ -32,7 +32,7 @@ require (
 	github.com/nu7hatch/gouuid v0.0.0-20131221200532-179d4d0c4d8d // indirect
 	github.com/tadvi/systray v0.0.0-20190226123456-11a2b8fa57af // indirect
 	github.com/tomnomnom/linkheader v0.0.0-20180905144013-02ca5825eb80 // indirect
-	golang.org/x/sys v0.4.0 // indirect
+	golang.org/x/sys v0.6.0 // indirect
 	golang.org/x/term v0.4.0 // indirect
 	golang.org/x/text v0.6.0 // indirect
 )
