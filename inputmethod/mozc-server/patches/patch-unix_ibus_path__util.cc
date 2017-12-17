$NetBSD: patch-unix_ibus_path__util.cc,v 1.1 2017/12/17 14:15:43 tsutsui Exp $

* use ${PREFIX} path

--- unix/ibus/path_util.cc.orig	2017-11-02 13:32:47.000000000 +0000
+++ unix/ibus/path_util.cc
@@ -30,7 +30,7 @@
 #include "unix/ibus/path_util.h"
 
 namespace {
-const char kInstalledDirectory[] = "/usr/share/ibus-mozc";
+const char kInstalledDirectory[] = "@PREFIX@/share/ibus-mozc";
 }
 
 namespace mozc {
