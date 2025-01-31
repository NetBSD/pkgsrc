$NetBSD: patch-gui_ExampleService_example.m,v 1.1 2025/01/31 12:56:16 wiz Exp $

Add missing header for getopt, fork, setsid.

--- gui/ExampleService/example.m.orig	2025-01-31 12:54:54.720487564 +0000
+++ gui/ExampleService/example.m
@@ -40,6 +40,7 @@
 #include "wgetopt.h"
 
 #include	<signal.h>
+#include	<unistd.h>
 
 #ifndef	NSIG
 #define	NSIG	32
