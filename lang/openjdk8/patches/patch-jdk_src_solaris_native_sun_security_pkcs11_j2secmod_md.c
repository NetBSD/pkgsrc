$NetBSD: patch-jdk_src_solaris_native_sun_security_pkcs11_j2secmod_md.c,v 1.1 2015/02/08 08:41:25 tnn Exp $

No RTLD_NOLOAD on NetBSD < 6, use RTLD_LAZY instead.

--- jdk/src/solaris/native/sun/security/pkcs11/j2secmod_md.c.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/src/solaris/native/sun/security/pkcs11/j2secmod_md.c
@@ -54,7 +54,7 @@ JNIEXPORT jlong JNICALL Java_sun_securit
     }
 
     // look up existing handle only, do not load
-#if defined(AIX)
+#if defined(AIX) || !defined(RTLD_NOLOAD)
     void *hModule = dlopen(libName, RTLD_LAZY);
 #else
     void *hModule = dlopen(libName, RTLD_NOLOAD);
