$NetBSD: patch-hotspot_src_share_vm_runtime_arguments.cpp,v 1.1 2015/02/12 06:18:17 tnn Exp $

Fix problem with ZERO build.

arguments.cpp:2089:9: error: 'is_sun4v' is not a member of 'VM_Version'

--- hotspot/src/share/vm/runtime/arguments.cpp.orig	2015-01-26 15:21:48.000000000 +0000
+++ hotspot/src/share/vm/runtime/arguments.cpp
@@ -2086,7 +2086,7 @@ bool Arguments::check_vm_args_consistenc
     // Issue a stern warning if the user has explicitly set
     // UseMemSetInBOT (it is known to cause issues), but allow
     // use for experimentation and debugging.
-    if (VM_Version::is_sun4v() && UseMemSetInBOT) {
+    if (UseMemSetInBOT) {
       assert(!FLAG_IS_DEFAULT(UseMemSetInBOT), "Error");
       warning("Experimental flag -XX:+UseMemSetInBOT is known to cause instability"
           " on sun4v; please understand that you are using at your own risk!");
