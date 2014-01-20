$NetBSD: patch-jdk_src_solaris_native_java_net_net__util__md.c,v 1.1 2014/01/20 19:25:11 joerg Exp $

--- jdk/src/solaris/native/java/net/net_util_md.c.orig	2014-01-05 21:54:15.000000000 +0000
+++ jdk/src/solaris/native/java/net/net_util_md.c
@@ -118,9 +118,9 @@ int getDefaultScopeID(JNIEnv *env) {
     static jfieldID ni_defaultIndexID;
     if (ni_class == NULL) {
         jclass c = (*env)->FindClass(env, "java/net/NetworkInterface");
-        CHECK_NULL(c);
+        CHECK_NULL_RETURN(c, 0);
         c = (*env)->NewGlobalRef(env, c);
-        CHECK_NULL(c);
+        CHECK_NULL_RETURN(c, 0);
         ni_defaultIndexID = (*env)->GetStaticFieldID(
             env, c, "defaultIndex", "I");
         ni_class = c;
