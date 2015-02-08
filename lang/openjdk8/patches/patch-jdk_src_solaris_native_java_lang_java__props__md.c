$NetBSD: patch-jdk_src_solaris_native_java_lang_java__props__md.c,v 1.1 2015/02/08 08:41:25 tnn Exp $

--- jdk/src/solaris/native/java/lang/java_props_md.c.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/src/solaris/native/java/lang/java_props_md.c
@@ -499,6 +499,11 @@ GetJavaProperties(JNIEnv *env)
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
