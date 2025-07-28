$NetBSD: patch-src_gnatprove_spark__report.adb,v 1.1 2025/07/28 07:00:55 dkazankov Exp $

Add NetBSD support

--- src/gnatprove/spark_report.adb.orig	2024-01-11 17:55:20.000000000 +0200
+++ src/gnatprove/spark_report.adb
@@ -1110,6 +1110,7 @@
                 | AArch64_Linux  => "Linux",
              when X86_64_Darwin  => "Darwin",
              when X86_64_FreeBSD => "FreeBSD",
+             when X86_64_NetBSD  => "NetBSD",
              when CodePeer_OS    => "CodePeer OS",
              when AArch64_Darwin => "Darwin");
 
