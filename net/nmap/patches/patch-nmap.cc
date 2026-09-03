$NetBSD: patch-nmap.cc,v 1.1 2026/09/03 07:16:25 adam Exp $

Fix build without Lua.

--- nmap.cc.orig	2026-09-03 07:11:21.781042421 +0000
+++ nmap.cc
@@ -1858,7 +1858,9 @@ void nmap_free_mem() {
   AllProbes::service_scan_free();
   traceroute_hop_cache_clear();
   nsock_set_default_engine(NULL);
+#ifndef NOLUA
   close_nse();
+#endif
 }
 
 int nmap_main(int argc, char *argv[]) {
