$NetBSD: patch-scripts_hexdump.sh,v 1.1 2022/07/24 10:13:38 leot Exp $

Avoid bash dependency, there is not any bash-ism in the script.

--- scripts/hexdump.sh.orig	2022-06-14 12:19:22.000000000 +0000
+++ scripts/hexdump.sh
@@ -1,9 +1,9 @@
-#!/bin/bash
+#!/bin/sh
 
 FILE=$1
 if [ ! -f "$FILE" ]
 then
-	echo usage: bash scripts/hexdump.sh input.ttf
+	echo usage: sh scripts/hexdump.sh input.ttf
 	exit 1
 fi
 
