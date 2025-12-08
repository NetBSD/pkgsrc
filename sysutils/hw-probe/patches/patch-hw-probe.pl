$NetBSD: patch-hw-probe.pl,v 1.2 2025/12/08 10:19:23 vins Exp $

* No need for cpuid; our lscpu package supports NetBSD.
* Use audioctl in place of sndstat on NetBSD/OpenBSD.

--- hw-probe.pl.orig	2025-01-11 17:52:38.000000000 +0000
+++ hw-probe.pl
@@ -3994,7 +3994,7 @@ sub probeHW()
             }
             elsif(isNetBSD())
             {
-                push(@NeedProgs, "usbctl", "curl"); # we have pcictl and usbdevs on NetBSD by default, TODO: cpuid?
+                push(@NeedProgs, "lscpu", "usbctl", "curl"); # we have pcictl and usbdevs on NetBSD by default
                 
                 if($Sys{"Arch"}!~/i386|amd64|aarch64/) {
                     @NeedProgs = grep {$_!~/dmidecode/} @NeedProgs;
@@ -4359,7 +4359,26 @@ sub probeHW()
             writeLog($LOG_DIR."/sndstat", $Sndstat);
         }
     }
-    
+
+    my $Audioctl = "";
+
+    if($Opt{"FixProbe"}) {
+        $Audioctl = readFile($FixProbe_Logs."/audioctl");
+    }
+    elsif(enabledLog("audioctl") and checkCmd("audioctl"))
+    {
+        listProbe("logs", "audioctl");
+        if(isOpenBSD()) {
+        $Audioctl = runCmd("audioctl 2>/dev/null");
+        }
+        elsif(isNetBSD()) {
+	$Audioctl = runCmd("audioctl -a | head -5 2>/dev/null");
+        }
+        if($Opt{"HWLogs"}) {
+            writeLog($LOG_DIR."/audioctl", $Audioctl);
+        }
+    }
+
     my $Neofetch = "";
     
     if($Opt{"FixProbe"}) {
@@ -17758,6 +17777,7 @@ my %EnabledLog_BSD = (
         "apm",
         "arcconf",
         "atactl",
+        "audioctl",
         "biosdecode",
         "curl",
         "dev",
@@ -18887,11 +18907,11 @@ sub scenario()
         my @Exclude = ();
         
         if($^O=~/openbsd|dragonfly/ or isNetBSD($^O))  {
-            push(@Exclude, "loader", "gpart", "gpart_list", "diskinfo", "camcontrol");
+            push(@Exclude, "loader", "gpart", "gpart_list", "diskinfo", "camcontrol", "sndstat");
         }
         
         if($^O=~/freebsd|dragonfly/) {
-            push(@Exclude, "disklabel");
+            push(@Exclude, "disklabel", "audioctl");
         }
         
         if(@Exclude)
