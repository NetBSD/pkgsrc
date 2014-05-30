$NetBSD: patch-installer_manifest.tcl,v 1.2 2014/05/30 11:32:22 joerg Exp $

--- installer/manifest.tcl.orig	2000-07-17 12:37:18.000000000 +0000
+++ installer/manifest.tcl
@@ -73,6 +73,7 @@ array set Manifest [list  \
     [file join installer file82.tcl]		{} \
     [file join installer file83.tcl]		{} \
     [file join installer file84.tcl]		{} \
+    [file join installer file86.tcl]		{} \
     [file join installer support.tcl]		{} \
     [file join installer mac.tcl]		{} \
     [file join installer macfile.tcl]		{} \
@@ -161,6 +162,7 @@ array set Manifest [list  \
     [file join lib tcl82.tcl]			{copy} \
     [file join lib tcl83.tcl]			{copy} \
     [file join lib tcl84.tcl]			{copy} \
+    [file join lib tcl86.tcl]			{copy} \
     [file join lib Unix.tcl]			{copy} \
     [file join lib Windows.tcl]			{copy} \
     [file join lib debug.tcl]			{copy} \
