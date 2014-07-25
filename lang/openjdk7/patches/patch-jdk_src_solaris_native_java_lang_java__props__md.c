$NetBSD: patch-jdk_src_solaris_native_java_lang_java__props__md.c,v 1.1 2014/07/25 20:35:14 ryoon Exp $

--- jdk/src/solaris/native/java/lang/java_props_md.c.orig	2014-06-14 20:38:31.000000000 +0000
+++ jdk/src/solaris/native/java/lang/java_props_md.c
@@ -476,6 +476,11 @@ GetJavaProperties(JNIEnv *env)
     {
 #ifdef MACOSX
         setOSNameAndVersion(&sprops);
+#elif defined(__DragonFly__)
+        struct utsname name;
+        uname(&name);
+        sprops.os_name = "DragonFlyBSD";
+        sprops.os_version = strdup(name.release);
 #else
         struct utsname name;
         uname(&name);
