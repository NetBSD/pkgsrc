$NetBSD: patch-jdk_test_sun_security_ec_TestEC.java,v 1.1 2015/02/08 08:41:25 tnn Exp $

Test fixes.

--- jdk/test/sun/security/ec/TestEC.java.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/test/sun/security/ec/TestEC.java
@@ -97,7 +97,7 @@ public class TestEC {
         // ClientJSSEServerJSSE fails on Solaris 11 when both SunEC and
         // SunPKCS11-Solaris providers are enabled.
         // Workaround:
-        // Security.removeProvider("SunPKCS11-Solaris");
+        Security.removeProvider("SunPKCS11-Solaris");
         new ClientJSSEServerJSSE().main(p);
 
         long stop = System.currentTimeMillis();
