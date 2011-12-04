$NetBSD: patch-src_org_omegat_util_StaticUtils.java,v 1.1.1.1 2011/12/04 20:33:55 ryoon Exp $

* Support $HOME/.omegat directory on NetBSD and DragonFly

--- src/org/omegat/util/StaticUtils.java.orig	2011-05-17 00:36:52.000000000 +0000
+++ src/org/omegat/util/StaticUtils.java
@@ -491,7 +491,7 @@ public class StaticUtils {
         }
         // Check for UNIX varieties
         // Solaris is generally detected as SunOS
-        else if (os.equals("Linux") || os.equals("SunOS") || os.equals("Solaris") || os.equals("FreeBSD")) {
+        else if (os.equals("Linux") || os.equals("SunOS") || os.equals("Solaris") || os.equals("FreeBSD") || os.equals("NetBSD") || os.equals("DragonFly")){
             // set the config dir to the user's home dir + "/.omegat/", so it's
             // hidden
             m_configDir = home + UNIX_CONFIG_DIR;
