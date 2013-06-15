$NetBSD: patch-jdk_test_java_lang_management_OperatingSystemMXBean_GetSystemLoadAverage.java,v 1.1 2013/06/15 09:31:06 jperkin Exp $

Test fixes.

--- jdk/test/java/lang/management/OperatingSystemMXBean/GetSystemLoadAverage.java.orig	2013-02-20 17:07:30.000000000 +0000
+++ jdk/test/java/lang/management/OperatingSystemMXBean/GetSystemLoadAverage.java
@@ -103,6 +103,8 @@ public class GetSystemLoadAverage {
                 ? output.split(" ")
                 : output.split(",");
         double expected = Double.parseDouble(lavg[0]);
+        // round to value to two decimals; some OSes report more (SmartOS at least)
+        expected = 0.01D * Math.round(expected / 0.01D);
         double lowRange = expected * (1 - DELTA);
         double highRange = expected * (1 + DELTA);
 
