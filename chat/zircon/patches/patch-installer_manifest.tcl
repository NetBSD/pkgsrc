$NetBSD: patch-installer_manifest.tcl,v 1.1 2012/08/21 21:41:03 marino Exp $

--- installer/manifest.tcl.orig	2000-07-17 12:37:18.000000000 +0000
+++ installer/manifest.tcl
@@ -73,6 +73,7 @@ array set Manifest [list  \
     [file join installer file82.tcl]		{} \
     [file join installer file83.tcl]		{} \
     [file join installer file84.tcl]		{} \
+    [file join installer file85.tcl]		{} \
     [file join installer support.tcl]		{} \
     [file join installer mac.tcl]		{} \
     [file join installer macfile.tcl]		{} \
@@ -161,6 +162,7 @@ array set Manifest [list  \
     [file join lib tcl82.tcl]			{copy} \
     [file join lib tcl83.tcl]			{copy} \
     [file join lib tcl84.tcl]			{copy} \
+    [file join lib tcl85.tcl]			{copy} \
     [file join lib Unix.tcl]			{copy} \
     [file join lib Windows.tcl]			{copy} \
     [file join lib debug.tcl]			{copy} \
