$NetBSD: patch-src_qconfirm-check.c,v 1.1 2019/07/09 18:23:15 schmonz Exp $

Rename local getline() to avoid duplicating a system-provided definition.

--- src/qconfirm-check.c.orig	2004-12-12 16:57:17.000000000 +0000
+++ src/qconfirm-check.c
@@ -24,7 +24,7 @@
 #include "wait.h"
 #include "sig.h"
 #include "lock.h"
-#include "getline.h"
+#include "qconfirm_getline.h"
 #include "seek.h"
 
 #define USAGE " [-mnbD] [-d dir ] [-i bytes ] [-t sec ] [prog]"
@@ -650,7 +650,7 @@ int main(int argc, const char **argv) {
 
   /* get mid */
   mid =0;
-  while ((i =getline(buffer_0, &sa)) > 0) {
+  while ((i =qconfirm_getline(buffer_0, &sa)) > 0) {
     if ((i == 1) && (sa.s[0] == '\n')) break; /* end of headers */
     for (i =0; i < sa.len; ++i)
       if (sa.s[i] < 32 || sa.s[i] > 126)
