$NetBSD: patch-src_inject.cc,v 1.1 2016/12/12 23:54:12 wiedi Exp $

Add support for RFC976 "From_ lines".
Some systems (e.g. Sun cron) generate UUCP "From_ lines" breaking header parsing.
Upstream bug: https://github.com/bruceg/nullmailer/pull/39

--- src/inject.cc.orig	2013-03-27 21:22:39.000000000 +0000
+++ src/inject.cc
@@ -347,11 +347,16 @@ bool read_header()
 {
   mystring cur_line;
   mystring whole;
+  bool first = true;
   for (;;) {
     if (!fin.getline(cur_line))
       cur_line = "";
     if(!cur_line || cur_line == "\r")
       break;
+    if(first && (cur_line.find_first_of("From ", 0) == 0 ||
+       cur_line.find_first_of(">From ", 0) == 0))
+      continue;
+    first = false;
     if(!!whole && is_continuation(cur_line)) {
       //if(!whole)
       //bad_hdr(cur_line, "First line cannot be a continuation line.");
