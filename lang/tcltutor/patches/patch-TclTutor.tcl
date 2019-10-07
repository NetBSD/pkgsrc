$NetBSD: patch-TclTutor.tcl,v 1.1 2019/10/07 14:37:34 kamil Exp $

- fix shebang
- disable logUsage+mailLog
- overwrite data dir

--- TclTutor.tcl.orig	2014-03-20 14:27:20.000000000 +0000
+++ TclTutor.tcl
@@ -1,8 +1,8 @@
-package provide app-tcltutor 1.0
 #!/bin/sh 
 # \
 exec wish "$0" "$@"
 
+package provide app-tcltutor 1.0
 package require Tk
 
 ;# NAME:   TclTutor.tcl
@@ -139,8 +139,8 @@ proc parseArgs {stateVar {throwError 1}}
 
     switch $tcl_platform(platform) {
       "unix"	{
-            set Tutor(sourceHome) [file dirname $argv0]
-            set Tutor(lessonHome) [file dirname $argv0]/lesson
+            set Tutor(sourceHome) @TCLTUTOR_LIBDATADIR@
+            set Tutor(lessonHome) @TCLTUTOR_LIBDATADIR@/lesson
 	    set Tutor(rcHome) $env(HOME)
             set Tutor(rcfile) [file join $Tutor(rcHome) .tcltutorrc]
             set Tutor(logFileName) [file join $Tutor(rcHome) .tcltutoract]
@@ -160,8 +160,8 @@ proc parseArgs {stateVar {throwError 1}}
       }
       "macintosh" -
       "mac"	{
-            set Tutor(sourceHome) [file dirname $argv0]
-            set Tutor(lessonHome) [file dirname $argv0]/lesson
+            set Tutor(sourceHome) @TCLTUTOR_LIBDATADIR@
+            set Tutor(lessonHome) @TCLTUTOR_LIBDATADIR@/lesson
 	    set Tutor(rcHome) [file dirname $argv0]
             set Tutor(rcfile) [file join $Tutor(rcHome) tcltutor.rc]
             set Tutor(logFileName) [file join $Tutor(rcHome) tcltutor.act]
@@ -174,7 +174,7 @@ proc parseArgs {stateVar {throwError 1}}
       }
    }
 
-set Tutor(noSaves) {sourceHome lessonHome}
+set Tutor(noSaves) {sourceHome lessonHome logUsage mailUsage}
 
 #
 #   check if a Scripted Document 
@@ -694,7 +694,7 @@ proc createDisplay {} {
         $mbf.file add command -label $l -command $l2
     }
     
-    if {[string match $tcl_platform(platform) "unix"]} {
+    if {0 && [string match $tcl_platform(platform) "unix"]} {
         if {$Tutor(logUsage)} {
            $mbf.file add command -label "Disable activity log" -command {set Tutor(logUsage) 0}
          } else {
@@ -1153,6 +1153,8 @@ proc SetFontSize {} {
 # 
 proc logUsage {str} {
     global Tutor
+
+    return
     
     if {$Tutor(logUsage) == 0} {return}
 
@@ -1180,6 +1182,9 @@ proc logUsage {str} {
 # 
 proc mailLog {} {
   global Tutor tcl_platform
+
+  return
+
   catch {close $Tutor(logFile)}
   
     switch $tcl_platform(platform) {
@@ -1388,4 +1393,3 @@ selectCourse [file join \
     [format "%s.%s" $Tutor(courseName) cfg]]
 
 applyOptions
-
