$NetBSD: patch-src_main.c,v 1.1 2024/09/23 06:44:51 wiz Exp $

freeglut  ERROR:
Function <glutCreateWindow> called without first calling 'glutInit'.

--- src/main.c.orig	2024-09-23 06:42:06.391623724 +0000
+++ src/main.c
@@ -256,6 +256,8 @@ main (int argc, char *argv[])
     }
 #endif
 
+  glutInit (&argc, argv);
+
   /* Perform program-level initialization. */
   program_initialization ();
 
