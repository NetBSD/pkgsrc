$NetBSD: patch-src_qconfirm-return.c,v 1.1 2019/07/09 18:23:15 schmonz Exp $

Rename local getline() to avoid duplicating a system-provided definition.

--- src/qconfirm-return.c.orig	2004-12-12 16:57:17.000000000 +0000
+++ src/qconfirm-return.c
@@ -17,5 +17,5 @@
 #include "qconfirm_id.h"
 #include "next_paragraph.h"
-#include "getline.h"
+#include "qconfirm_getline.h"
 
 #define USAGE " [-n limit ] [dir]"
@@ -76,5 +76,5 @@ int main(int argc, const char **argv) {
 
   /* 'Hi. This is the' */
-  if ((r =getline(buffer_0, &sa)) == -1)
+  if ((r =qconfirm_getline(buffer_0, &sa)) == -1)
     strerr_die2x(0, WARNING, "empty body.");
   if ((sa.len < 15) || ! str_start(sa.s, "Hi. This is the")) die_noqsbmf();
@@ -82,5 +82,5 @@ int main(int argc, const char **argv) {
 
   /* failure paragraph */
-  if (getline(buffer_0, &sa) == -1) die_noqsbmf();
+  if (qconfirm_getline(buffer_0, &sa) == -1) die_noqsbmf();
   /* create id */
   if ((sa.len < 4) || (sa.s[0] != '<') ||
@@ -101,10 +101,10 @@ int main(int argc, const char **argv) {
 
   /* break paragraph */
-  if (getline(buffer_0, &sa) == -1) die_noqsbmf();
+  if (qconfirm_getline(buffer_0, &sa) == -1) die_noqsbmf();
   if (! sa.len || (sa.s[0] != '-')) die_noqsbmf();
   if (next_paragraph(buffer_0) == -1) die_noqsbmf();
 
   /* original message */
-  while ((r =getline(buffer_0, &sa)) > 0) {
+  while ((r =qconfirm_getline(buffer_0, &sa)) > 0) {
     int at, dash;
 
