$NetBSD: patch-snow.h,v 1.1 2026/03/17 07:25:03 nia Exp $

Fix implicit declaration of strcmp in main.c.

--- snow.h.orig	2026-03-17 07:07:40.470015964 +0000
+++ snow.h
@@ -19,6 +19,7 @@
 #define _SNOW_H
 
 #include <stdio.h>
+#include <string.h>
 
 
 /*
