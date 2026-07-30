$NetBSD: patch-make-config.sh,v 1.2 2026/07/30 12:03:59 ktnb Exp $

Exclude sb-simd module from build, it depends on the host features.

--- make-config.sh.orig	2026-07-28 08:09:25.000000000 +0000
+++ make-config.sh
@@ -553,12 +553,8 @@ echo "(lambda (features) (set-difference (union featur
 echo ';;;; See make-config.sh.' >> $ltf
 echo "(lambda (features) (set-difference (union features (list :${sbcl_arch}$WITH_FEATURES" >> $ltf
 
-# Automatically block sb-simd on non-x86 platforms, at least for now.
-case "$sbcl_arch" in
-    x86-64) ;;
-    arm64) ;;
-    *) SBCL_CONTRIB_BLOCKLIST="$SBCL_CONTRIB_BLOCKLIST sb-simd" ;;
-esac
+# Don't build sb-simd on any platform
+SBCL_CONTRIB_BLOCKLIST="$SBCL_CONTRIB_BLOCKLIST sb-simd"
 case "$sbcl_os" in
     linux) ;; *) SBCL_CONTRIB_BLOCKLIST="$SBCL_CONTRIB_BLOCKLIST sb-perf" ;;
 esac
