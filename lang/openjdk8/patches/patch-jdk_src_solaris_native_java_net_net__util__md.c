$NetBSD: patch-jdk_src_solaris_native_java_net_net__util__md.c,v 1.1 2015/02/08 08:41:25 tnn Exp $

--- jdk/src/solaris/native/java/net/net_util_md.c.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/src/solaris/native/java/net/net_util_md.c
@@ -92,9 +92,9 @@ void setDefaultScopeID(JNIEnv *env, stru
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
