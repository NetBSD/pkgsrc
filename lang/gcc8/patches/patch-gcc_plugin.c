$NetBSD: patch-gcc_plugin.c,v 1.1 2023/09/05 16:54:20 vins Exp $

Support dynamic link interface functions.

--- gcc/plugin.c.orig	2022-05-27 07:21:11.335381405 +0000
+++ gcc/plugin.c
@@ -20,6 +20,8 @@ along with GCC; see the file COPYING3.
 /* This file contains the support for GCC plugin mechanism based on the
    APIs described in doc/plugin.texi.  */
 
+#include <dlfcn.h>
+
 #include "config.h"
 #include "system.h"
 #include "coretypes.h"
