$NetBSD: patch-hw-probe.pl,v 1.1 2025/01/13 19:22:23 vins Exp $

No need for cpuid; our lscpu package supports NetBSD.

--- hw-probe.pl.orig	2025-01-13 18:54:37.940812334 +0000
+++ hw-probe.pl
@@ -3994,7 +3994,7 @@ sub probeHW()
             }
             elsif(isNetBSD())
             {
-                push(@NeedProgs, "usbctl", "curl"); # we have pcictl and usbdevs on NetBSD by default, TODO: cpuid?
+                push(@NeedProgs, "lscpu", "usbctl", "curl"); # we have pcictl and usbdevs on NetBSD by default
                 
                 if($Sys{"Arch"}!~/i386|amd64|aarch64/) {
                     @NeedProgs = grep {$_!~/dmidecode/} @NeedProgs;
