$NetBSD: patch-src_gnatprove_spark__report.adb,v 1.1 2025/07/10 12:43:03 dkazankov Exp $

Add NetBSD support

--- src/gnatprove/spark_report.adb.orig	2023-01-05 11:22:11.000000000 +0200
+++ src/gnatprove/spark_report.adb
@@ -1086,6 +1086,7 @@
              when X86_Linux   | X86_64_Linux   => "Linux",
              when X86_64_Darwin                => "Darwin",
              when X86_64_FreeBSD               => "FreeBSD",
+             when X86_64_NetBSD                => "NetBSD",
              when CodePeer_OS                  => "CodePeer OS",
              when AArch64_Darwin               => "Darwin");
 
