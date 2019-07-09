$NetBSD: patch-src_qconfirm-check-mid.c,v 1.1 2019/07/09 18:23:15 schmonz Exp $

Rename local getline() to avoid duplicating a system-provided definition.

--- src/qconfirm-check-mid.c.orig	2004-12-12 16:57:17.000000000 +0000
+++ src/qconfirm-check-mid.c
@@ -16,5 +16,5 @@
 #include "str.h"
 #include "open.h"
-#include "getline.h"
+#include "qconfirm_getline.h"
 
 #define USAGE " [-va] [ mid ... ]"
@@ -143,5 +143,5 @@ int main(int argc, char **argv) {
   }
 
-  while ((i =getline(buffer_0, &line)) > 0) {
+  while ((i =qconfirm_getline(buffer_0, &line)) > 0) {
     if ((i == 1) && (line.s[0] == '\n')) break; /* end of headers */
     /* lowercase line */
