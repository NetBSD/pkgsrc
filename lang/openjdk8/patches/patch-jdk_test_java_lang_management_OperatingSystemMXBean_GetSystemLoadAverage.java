$NetBSD: patch-jdk_test_java_lang_management_OperatingSystemMXBean_GetSystemLoadAverage.java,v 1.1 2015/02/08 08:41:25 tnn Exp $

Test fixes.

--- jdk/test/java/lang/management/OperatingSystemMXBean/GetSystemLoadAverage.java.orig	2015-02-02 15:37:13.000000000 +0000
+++ jdk/test/java/lang/management/OperatingSystemMXBean/GetSystemLoadAverage.java
@@ -105,6 +105,8 @@ public class GetSystemLoadAverage {
                 ? output.split(" ")
                 : output.split(",");
         double expected = Double.parseDouble(lavg[0]);
+        // round to value to two decimals; some OSes report more (SmartOS at least)
+        expected = 0.01D * Math.round(expected / 0.01D);
         double lowRange = expected * (1 - DELTA);
         double highRange = expected * (1 + DELTA);
 
