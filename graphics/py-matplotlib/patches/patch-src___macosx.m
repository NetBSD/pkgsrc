$NetBSD: patch-src___macosx.m,v 1.1 2017/05/29 20:59:21 adam Exp $

Do not complain about Python.framework and allow working from command-line.

--- src/_macosx.m.orig	2017-05-10 17:14:04.000000000 +0000
+++ src/_macosx.m
@@ -3068,9 +3068,8 @@ static bool verify_framework(void)
     switch (activationPolicy) {
         case NSApplicationActivationPolicyRegular:
         case NSApplicationActivationPolicyAccessory:
-            return true;
         case NSApplicationActivationPolicyProhibited:
-            break;
+            return true;
     }
 #else
     ProcessSerialNumber psn;
