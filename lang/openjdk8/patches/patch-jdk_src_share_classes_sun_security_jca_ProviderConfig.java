$NetBSD: patch-jdk_src_share_classes_sun_security_jca_ProviderConfig.java,v 1.1 2017/03/30 12:57:11 jperkin Exp $

Fix https://www.illumos.org/issues/7227

--- jdk/src/share/classes/sun/security/jca/ProviderConfig.java.orig	2017-01-31 13:43:12.000000000 +0000
+++ jdk/src/share/classes/sun/security/jca/ProviderConfig.java
@@ -102,15 +102,14 @@ final class ProviderConfig {
         Boolean o = AccessController.doPrivileged(
                                 new PrivilegedAction<Boolean>() {
             public Boolean run() {
-                File file = new File("/usr/lib/libpkcs11.so");
-                if (file.exists() == false) {
-                    return Boolean.FALSE;
-                }
-                if ("false".equalsIgnoreCase(System.getProperty
+                if ("true".equalsIgnoreCase(System.getProperty
                         ("sun.security.pkcs11.enable-solaris"))) {
-                    return Boolean.FALSE;
+                    File file = new File("/usr/lib/libpkcs11.so");
+                    if (file.exists()) {
+                        return Boolean.TRUE;
+                    }
                 }
-                return Boolean.TRUE;
+                return Boolean.FALSE;
             }
         });
         if (o == Boolean.FALSE) {
