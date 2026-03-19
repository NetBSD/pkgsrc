$NetBSD: patch-tnef.c,v 1.1 2026/03/19 07:54:10 nia Exp $

Fix implicit function declarations.

--- tnef.c.orig	1997-07-23 00:15:59.000000000 +0000
+++ tnef.c
@@ -30,6 +30,8 @@
  ***************************************************************************/
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <sys/stat.h>
 #include "config.h"
 #include "tnef.h"
@@ -41,6 +43,8 @@
 int Verbose = FALSE;
 int SaveData = FALSE;
 
+int save_attach_data(char *, uint8 *, uint32);
+
 /* Some systems don't like to read unaligned data */
 uint32 read_32(uint8 *tsp)
 {
