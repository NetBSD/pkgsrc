$NetBSD: patch-man_example-filter.sh,v 1.1 2020/08/18 02:12:44 tnn Exp $

Shell portability.

--- man/example-filter.sh.orig	2018-08-03 03:32:48.000000000 +0000
+++ man/example-filter.sh
@@ -4,14 +4,14 @@
 
 while read line; do
 	echo "$line" | while read -n 1 char; do
-		if [[ $char == "%" ]]; then
+		if [ $char = "%" ]; then
 			echo -n '%'
 			continue
 		fi
 		ord=$(printf '%d' "'$char")
-		if [[ $ord -eq 0 ]]; then
+		if [ $ord -eq 0 ]; then
 			printf ' '
-		elif [[ $ord -gt 127 ]]; then
+		elif [ $ord -gt 127 ]; then
 			printf '\[u%X]' "'$char"
 		else
 			printf "$char"
