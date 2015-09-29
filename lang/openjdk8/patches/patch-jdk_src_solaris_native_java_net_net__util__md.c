$NetBSD: patch-jdk_src_solaris_native_java_net_net__util__md.c,v 1.2 2015/09/29 14:55:45 ryoon Exp $

--- jdk/src/solaris/native/java/net/net_util_md.c.orig	2015-09-28 21:01:39.000000000 +0000
+++ jdk/src/solaris/native/java/net/net_util_md.c
@@ -96,9 +96,9 @@ void setDefaultScopeID(JNIEnv *env, stru
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
         CHECK_NULL(ni_defaultIndexID);
