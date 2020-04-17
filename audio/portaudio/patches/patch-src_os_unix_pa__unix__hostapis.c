$NetBSD: patch-src_os_unix_pa__unix__hostapis.c,v 1.1 2020/04/17 15:50:03 nia Exp $

Sun/NetBSD audio support.

--- src/os/unix/pa_unix_hostapis.c.orig	2016-10-30 01:23:04.000000000 +0000
+++ src/os/unix/pa_unix_hostapis.c
@@ -45,6 +45,7 @@
 PaError PaJack_Initialize( PaUtilHostApiRepresentation **hostApi, PaHostApiIndex index );
 PaError PaAlsa_Initialize( PaUtilHostApiRepresentation **hostApi, PaHostApiIndex index );
 PaError PaOSS_Initialize( PaUtilHostApiRepresentation **hostApi, PaHostApiIndex index );
+PaError PaSun_Initialize( PaUtilHostApiRepresentation **hostApi, PaHostApiIndex index );
 /* Added for IRIX, Pieter, oct 2, 2003: */
 PaError PaSGI_Initialize( PaUtilHostApiRepresentation **hostApi, PaHostApiIndex index );
 /* Linux AudioScience HPI */
@@ -69,6 +70,10 @@ PaUtilHostApiInitializer *paHostApiIniti
 
 #else   /* __linux__ */
 
+#if PA_USE_SUN
+        PaSun_Initialize,
+#endif
+
 #if PA_USE_OSS
         PaOSS_Initialize,
 #endif
