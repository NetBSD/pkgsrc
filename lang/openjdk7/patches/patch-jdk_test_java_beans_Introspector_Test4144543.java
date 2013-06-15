$NetBSD: patch-jdk_test_java_beans_Introspector_Test4144543.java,v 1.1 2013/06/15 09:31:06 jperkin Exp $

Test fixes.

--- jdk/test/java/beans/Introspector/Test4144543.java.orig	2013-02-20 17:07:30.000000000 +0000
+++ jdk/test/java/beans/Introspector/Test4144543.java
@@ -34,7 +34,8 @@ import java.beans.PropertyDescriptor;
 
 public class Test4144543 {
     public static void main(String[] args) throws Exception {
-        Class type = Beans.instantiate(null, "Test4144543").getClass();
+        // running under jtreg -agentvm: system classloader can't find this class (separate classloader?)
+        Class type = Beans.instantiate(Test4144543.class.getClassLoader(), "Test4144543").getClass();
 
         // try all the various places that this would break before
 
