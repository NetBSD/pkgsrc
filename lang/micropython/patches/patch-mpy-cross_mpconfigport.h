$NetBSD: patch-mpy-cross_mpconfigport.h,v 1.2 2019/09/24 12:17:40 sevan Exp $

Modern *BSDs declare alloca() in <stdlib.h>

--- mpy-cross/mpconfigport.h.orig	2017-08-23 01:50:10.000000000 +0000
+++ mpy-cross/mpconfigport.h
@@ -115,7 +115,7 @@ typedef long mp_off_t;
 #endif
 
 // We need to provide a declaration/definition of alloca()
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #include <stdlib.h>
 #elif defined( _WIN32 )
 #include <malloc.h>
