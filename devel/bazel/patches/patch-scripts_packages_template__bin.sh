$NetBSD: patch-scripts_packages_template__bin.sh,v 1.1 2024/01/01 12:00:58 ryoon Exp $

--- scripts/packages/template_bin.sh.orig	2023-11-28 16:39:59.898140894 +0000
+++ scripts/packages/template_bin.sh
@@ -115,6 +115,10 @@ if [ -z "${JAVA_HOME-}" ]; then
       JAVA_HOME="/usr/local/openjdk8"
       BASHRC="~/.bashrc"
       ;;
+    netbsd)
+      JAVA_HOME="/usr/pkg/java/openjdk8"
+      BASHRC="~/.bashrc"
+      ;;
     openbsd)
       JAVA_HOME="/usr/local/jdk-1.8.0"
       BASHRC="~/.bashrc"
