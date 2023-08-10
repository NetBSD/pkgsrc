$NetBSD: patch-ui_feed.go,v 1.1 2023/08/10 18:15:01 sjmulder Exp $

Patched version of 'beeep' with fixes for Illumos.

--- ui/feed.go.orig	2023-01-26 17:42:48.000000000 +0000
+++ ui/feed.go
@@ -10,7 +10,7 @@ import (
 	"github.com/RasmusLindroth/tut/feed"
 	"github.com/RasmusLindroth/tut/util"
 	"github.com/gdamore/tcell/v2"
-	"github.com/gen2brain/beeep"
+	"github.com/sjmulder/beeep"
 	"github.com/rivo/tview"
 )
 
