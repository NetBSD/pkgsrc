$NetBSD: patch-src_qconfirm-notice.c,v 1.1 2019/07/09 18:23:15 schmonz Exp $

Rename local getline() to avoid duplicating a system-provided definition.

--- src/qconfirm-notice.c.orig	2004-12-12 16:57:17.000000000 +0000
+++ src/qconfirm-notice.c
@@ -17,7 +17,7 @@
 #include "open.h"
 #include "openreadclose.h"
 #include "buffer.h"
-#include "getline.h"
+#include "qconfirm_getline.h"
 #include "str.h"
 #include "byte.h"
 #include "scan.h"
@@ -386,7 +386,7 @@ int main(int argc, const char **argv) {
   }
 
   /* check for confirmation request message */
-  while ((i =getline(buffer_0, &sa)) > 0) {
+  while ((i =qconfirm_getline(buffer_0, &sa)) > 0) {
     if ((i == 1) && (sa.s[0] == '\n')) break; /* end of headers */
     if (request && reply_to.s) break;
     for (i =0; i < sa.len; ++i) {
