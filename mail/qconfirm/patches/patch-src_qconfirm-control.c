$NetBSD: patch-src_qconfirm-control.c,v 1.1 2019/07/09 18:23:15 schmonz Exp $

Rename local getline() to avoid duplicating a system-provided definition.

--- src/qconfirm-control.c.orig	2004-12-12 16:57:17.000000000 +0000
+++ src/qconfirm-control.c
@@ -9,7 +9,7 @@
 #include "qconfirm_inject.h"
 #include "qconfirm_key.h"
 #include "next_paragraph.h"
-#include "getline.h"
+#include "qconfirm_getline.h"
 #include "strerr.h"
 #include "error.h"
 #include "buffer.h"
@@ -262,7 +262,7 @@ int process() {
   if (! stralloc_copys(&args, "")) die_nomem();
 
   /* lines */
-  while ((r =getline(buffer_0, &sa)) > 0) {
+  while ((r =qconfirm_getline(buffer_0, &sa)) > 0) {
     if (sa.s[0] == '\n') continue;
     if ((sa.len > 2) && str_start(sa.s, qcontrol_quote)) {
       int i, j;
