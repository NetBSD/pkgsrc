$NetBSD: patch-hints_darwin.sh,v 1.8 2020/07/22 15:23:57 sjmulder Exp $

Support for macOS 11 'Big Sur', imported from open pull request:
https://github.com/Perl/perl5/pull/17946

--- hints/darwin.sh.orig	2019-10-21 11:20:16.000000000 +0000
+++ hints/darwin.sh
@@ -301,7 +301,7 @@ case "$osvers" in  # Note: osvers is the
    # We now use MACOSX_DEPLOYMENT_TARGET, if set, as an override by
    # capturing its value and adding it to the flags.
     case "$MACOSX_DEPLOYMENT_TARGET" in
-    10.*)
+    10.* | 11.*)
       add_macosx_version_min ccflags $MACOSX_DEPLOYMENT_TARGET
       add_macosx_version_min ldflags $MACOSX_DEPLOYMENT_TARGET
       ;;
@@ -313,7 +313,7 @@ case "$osvers" in  # Note: osvers is the
 
 *** Unexpected MACOSX_DEPLOYMENT_TARGET=$MACOSX_DEPLOYMENT_TARGET
 ***
-*** Please either set it to 10.something, or to empty.
+*** Please either set it to 10.something, 11.something or to empty.
 
 EOM
       exit 1
@@ -327,7 +327,7 @@ EOM
     # "ProductVersion:    10.11"     "10.11"
         prodvers=`sw_vers|awk '/^ProductVersion:/{print $2}'|awk -F. '{print $1"."$2}'`
     case "$prodvers" in
-    10.*)
+    10.* | 11.*)
       add_macosx_version_min ccflags $prodvers
       add_macosx_version_min ldflags $prodvers
       ;;
@@ -342,11 +342,11 @@ EOM
       exit 1
     esac
 
-    # The X in 10.X
+    prodvers_major=$(echo $prodvers|awk -F. '{print $1}')
     prodvers_minor=$(echo $prodvers|awk -F. '{print $2}')
 
     # macOS (10.12) deprecated syscall().
-    if [ "$prodvers_minor" -ge 12 ]; then
+    if [[ ( "$prodvers_minor" -ge 12 && "$prodvers_major" -eq 10 ) || "$prodvers_major" -ge 11 ]]; then
         d_syscall='undef'
         # If deploying to pre-10.12, suppress Time::HiRes's detection of the system clock_gettime()
         case "$MACOSX_DEPLOYMENT_TARGET" in
