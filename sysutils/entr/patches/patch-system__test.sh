$NetBSD: patch-system__test.sh,v 1.1 2020/06/13 21:51:26 leot Exp $

Do not use non-portable `==' test(1) operator.

--- system_test.sh.orig	2020-04-20 16:02:05.000000000 +0000
+++ system_test.sh
@@ -22,7 +22,7 @@ typeset -i tests=0
 function try { let tests+=1; this="$1"; }
 
 function assert {
-	[[ "$1" == "$2" ]] && { printf "."; return; }
+	[[ "$1" = "$2" ]] && { printf "."; return; }
 	printf "\nFAIL: $this\n'$1' != '$2'\n"; exit 1
 }
 function skip { printf "s"; }
@@ -110,7 +110,7 @@ try "fail to exec an command using one-s
 
 try "restart a server when a file is modified using one-shot option"
 	setup
-	if [ $(uname) == 'Linux' ]; then
+	if [ $(uname) = 'Linux' ]; then
 		skip "GNU nc spins while retrying SELECT(2); busybox does not support domain sockets"
 	else
 		ls $tmp/file2 | ./entr -rz nc -l -U $tmp/nc.s >> $tmp/exec.out &
