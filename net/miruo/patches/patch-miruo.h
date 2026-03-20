$NetBSD: patch-miruo.h,v 1.1 2026/03/20 20:28:21 nia Exp $

Fix implicit function declarations.

--- miruo.h.orig	2026-03-20 20:10:32.540287944 +0000
+++ miruo.h
@@ -2,6 +2,7 @@
 #include "config.h"
 #endif
 #define _GNU_SOURCE
+#include<ctype.h>
 #include<stdio.h>
 #include<unistd.h>
 #include<stdlib.h>
