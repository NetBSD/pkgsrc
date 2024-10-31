$NetBSD: patch-make-config.sh,v 1.1 2024/10/31 16:12:16 rjs Exp $

Exclude sb-simd module from build, it depends on the host features.

--- make-config.sh.orig	2024-10-30 20:33:13.000000000 +0000
+++ make-config.sh
@@ -542,10 +542,8 @@ echo ';;;; Please do not edit it by hand
 echo ';;;; See make-config.sh.' >> $ltf
 echo "(lambda (features) (set-difference (union features (list :${sbcl_arch}$WITH_FEATURES" >> $ltf
 
-# Automatically block sb-simd on non-x86 platforms, at least for now.
-case "$sbcl_arch" in
-    x86-64) ;; *) SBCL_CONTRIB_BLOCKLIST="$SBCL_CONTRIB_BLOCKLIST sb-simd" ;;
-esac
+# Don't build sb-simd on any platform
+SBCL_CONTRIB_BLOCKLIST="$SBCL_CONTRIB_BLOCKLIST sb-simd"
 case "$sbcl_os" in
     linux) ;; *) SBCL_CONTRIB_BLOCKLIST="$SBCL_CONTRIB_BLOCKLIST sb-perf" ;;
 esac
