$NetBSD: patch-mkjambase.c,v 1.1 2026/02/10 20:17:59 jakllsch Exp $

Explicit int return type for main().

--- mkjambase.c.orig	2026-02-10 18:07:54.048821831 +0000
+++ mkjambase.c
@@ -24,6 +24,7 @@
 # include <stdio.h>
 # include <string.h>
 
+int
 main( int argc, char **argv, char **envp )
 {
 	char buf[ 1024 ];
