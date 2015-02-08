$NetBSD: patch-jdk_test_java_beans_Introspector_4168475_Test4168475.java,v 1.1 2015/02/08 08:41:25 tnn Exp $

Test fixes.

--- jdk/test/java/beans/Introspector/4168475/Test4168475.java.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/test/java/beans/Introspector/4168475/Test4168475.java
@@ -41,6 +41,8 @@ public class Test4168475 {
     private static final String[] PATH = {"infos"};
 
     public static void main(String[] args) throws IntrospectionException {
+        // running under jtreg -agentvm: system classloader can't find this class (separate classloader?)
+        Thread.currentThread().setContextClassLoader(Test4168475.class.getClassLoader());
         Introspector.setBeanInfoSearchPath(PATH);
         BeanInfo info = Introspector.getBeanInfo(Component.class);
         PropertyDescriptor[] pds = info.getPropertyDescriptors();
