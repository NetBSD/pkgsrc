$NetBSD: patch-gcc_config_rs6000_morphos.c,v 1.1 2020/04/14 22:02:21 js Exp $

--- gcc/config/rs6000/morphos.c.orig	2020-01-25 16:25:31.000000000 +0000
+++ gcc/config/rs6000/morphos.c
@@ -80,6 +80,7 @@
 /* mclib */
 //const char *morphos_mclib_name = (char *)0;
 
+#ifdef __MORPHOS__
 #define STACKSIZE 2097152
 #define str(s) #s
 #define sstr(s) str(s)
@@ -94,6 +95,7 @@ asm("\n"
 "        .section \".text\"\n"
 "        .align  2\n"
 );
+#endif
 
 /* mbaserel32 */
 rtx morphos_legitimize_baserel_address(rtx addr)
