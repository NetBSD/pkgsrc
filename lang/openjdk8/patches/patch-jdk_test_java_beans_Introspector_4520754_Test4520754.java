$NetBSD: patch-jdk_test_java_beans_Introspector_4520754_Test4520754.java,v 1.1 2015/02/08 08:41:25 tnn Exp $

Test fixes.

--- jdk/test/java/beans/Introspector/4520754/Test4520754.java.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/test/java/beans/Introspector/4520754/Test4520754.java
@@ -56,6 +56,8 @@ public class Test4520754 {
     };
 
     public static void main(String[] args) {
+        // running under jtreg -agentvm: system classloader can't find this class (separate classloader?)
+        Thread.currentThread().setContextClassLoader(Test4520754.class.getClassLoader());
         // ensure that 4168475 does not regress
         test4168475(Component.class);
         // AWT classes (com.sun.beans.infos.ComponentBeanInfo)
