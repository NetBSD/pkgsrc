$NetBSD: patch-TSRM_threads.m4,v 1.1 2024/12/01 16:11:56 taca Exp $

Fix shell syntax.

--- TSRM/threads.m4.orig	2019-01-09 09:54:13.000000000 +0000
+++ TSRM/threads.m4
@@ -90,6 +90,7 @@ int main() {
   case $host_alias in
   *netware*)
     pthreads_working=yes
+    ;;
   esac
 ]
 ) ] )dnl
