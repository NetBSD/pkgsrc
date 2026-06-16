# $NetBSD: patch-acinclude.m4,v 1.1 2026/06/16 09:43:38 martin Exp $

Make configure work with newer compiler C standard defaults

--- acinclude.m4.orig	2017-06-03 17:35:56.000000000 +0200
+++ acinclude.m4	2026-06-14 21:22:06.431244841 +0200
@@ -340,7 +340,7 @@ AC_COMPILE_IFELSE(
 AC_COMPILE_IFELSE(
 [AC_LANG_SOURCE([
   #include <osipparser2/osip_parser.h>
-  main() {
+  int main() {
   osip_message_t t;
   int  e;
   e=t.contacts.nb_elt;
