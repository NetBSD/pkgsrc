$NetBSD: patch-build_test-rrd.c,v 1.1 2025/12/18 10:09:22 wiz Exp $

Adapt for recent rrdtool.

--- build/test-rrd.c.orig	2025-12-18 09:52:58.681306447 +0000
+++ build/test-rrd.c
@@ -4,7 +4,7 @@
 
 int main(int argc, char *argv[])
 {
-	char *rrdargs[] = {
+	const char *rrdargs[] = {
 		"rrdgraph",
 		"xymongen.png",
 		"-s", "e - 48d",
