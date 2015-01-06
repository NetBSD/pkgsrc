$NetBSD: patch-jdk_make_tools_src_build_tools_generatecurrencydata_GenerateCurrencyData.java,v 1.1 2015/01/06 11:19:19 jperkin Exp $

Extend valid currency data to 15 years to avoid lag in upstream updates.

--- jdk/make/tools/src/build/tools/generatecurrencydata/GenerateCurrencyData.java.orig	2014-11-02 07:18:20.000000000 +0000
+++ jdk/make/tools/src/build/tools/generatecurrencydata/GenerateCurrencyData.java
@@ -281,8 +281,8 @@ public class GenerateCurrencyData {
             checkCurrencyCode(newCurrency);
             String timeString = currencyInfo.substring(4, length - 4);
             long time = format.parse(timeString).getTime();
-            if (Math.abs(time - System.currentTimeMillis()) > ((long) 10) * 365 * 24 * 60 * 60 * 1000) {
-                throw new RuntimeException("time is more than 10 years from present: " + time);
+            if (Math.abs(time - System.currentTimeMillis()) > ((long) 15) * 365 * 24 * 60 * 60 * 1000) {
+                throw new RuntimeException("time is more than 15 years from present: " + time);
             }
             specialCaseCutOverTimes[specialCaseCount] = time;
             specialCaseOldCurrencies[specialCaseCount] = oldCurrency;
