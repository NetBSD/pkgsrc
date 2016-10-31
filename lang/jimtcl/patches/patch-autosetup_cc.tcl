$NetBSD: patch-autosetup_cc.tcl,v 1.1 2016/10/31 01:15:12 kamil Exp $

Backport upstream patch:

From 7d5a6e3b6f19a5c9260c131f428711320da452a0 Mon Sep 17 00:00:00 2001
From: Steve Bennett <steveb@workware.net.au>
Date: Wed, 26 Oct 2016 19:52:06 +1000
Subject: [PATCH] build: update autosetup for LIBS/LDFLAGS fix

	343be844 cc tests should use LIBS and LDFLAGS

Signed-off-by: Steve Bennett <steveb@workware.net.au>

--- autosetup/cc.tcl.orig	2016-09-04 04:14:05.000000000 +0000
+++ autosetup/cc.tcl
@@ -210,7 +210,7 @@ proc cc-check-members {args} {
 #
 # If the function is found, the feature is defined and lib_$function is defined
 # to -l$lib where the function was found, or "" if no library required.
-# In addition, -l$lib is added to the LIBS define.
+# In addition, -l$lib is prepended to the LIBS define.
 #
 # If additional libraries may be needed for linking, they should be specified
 # as $extralibs as "-lotherlib1 -lotherlib2".
@@ -232,7 +232,8 @@ proc cc-check-function-in-lib {function 
 					if {[cctest_function $function]} {
 						msg-result -l$lib
 						define lib_$function -l$lib
-						define-append LIBS -l$lib
+						# prepend to LIBS
+						define LIBS "-l$lib [get-define LIBS]"
 						incr found
 						break
 					}
@@ -498,13 +499,17 @@ proc cctest {args} {
 		}
 	}
 
-	if {!$opts(-link)} {
+	if {$opts(-link)} {
+		lappend cmdline {*}[get-define LDFLAGS]
+	} else {
 		set tmp conftest__.o
 		lappend cmdline -c
 	}
 	lappend cmdline {*}$opts(-cflags) {*}[get-define cc-default-debug ""]
-
 	lappend cmdline $src -o $tmp {*}$opts(-libs)
+	if {$opts(-link)} {
+		lappend cmdline {*}[get-define LIBS]
+	}
 
 	# At this point we have the complete command line and the
 	# complete source to be compiled. Get the result from cache if
