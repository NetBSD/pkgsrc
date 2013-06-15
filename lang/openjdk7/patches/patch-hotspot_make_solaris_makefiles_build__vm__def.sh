$NetBSD: patch-hotspot_make_solaris_makefiles_build__vm__def.sh,v 1.1 2013/06/15 09:31:05 jperkin Exp $

Fix path to nm.

--- hotspot/make/solaris/makefiles/build_vm_def.sh.orig	2013-02-19 23:21:59.000000000 +0000
+++ hotspot/make/solaris/makefiles/build_vm_def.sh
@@ -1,6 +1,6 @@
 #!/bin/sh
 
-/usr/ccs/bin/nm -p $* \
+/usr/bin/nm -p $* \
     | awk '{
           if ($2 == "U") next
           if ($3 ~ /^__1c.*__vtbl_$/ || $3 ~ /^gHotSpotVM/) print "\t" $3 ";"
