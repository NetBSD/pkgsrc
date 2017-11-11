$NetBSD: patch-test.sh,v 1.1 2017/11/11 19:43:06 maya Exp $

Avoid hard coding /bin/bash so much

--- test.sh.orig	2017-11-11 19:17:54.549032453 +0000
+++ test.sh
@@ -698,7 +698,7 @@ for addr in proxy; do
     done
     echo $OPTS
     # prepare dummy server
-    $SOCAT tcp-l:$PORT,reuseaddr,crlf exec:"/bin/bash proxyecho.sh" || echo "cannot start proxyecho.sh" >&2 &
+    $SOCAT tcp-l:$PORT,reuseaddr,crlf exec:"bash proxyecho.sh" || echo "cannot start proxyecho.sh" >&2 &
 	pid=$!
 	sleep 1
     for o in $(filloptionvalues $OPTS|tr ',' ' '); do
@@ -4548,7 +4548,7 @@ te="$td/test$N.stderr"
 tdiff="$td/test$N.diff"
 da="test$N $(date) $RANDOM"; da="$da$($ECHO '\r')"
 #CMD2="$TRACE $SOCAT tcp4-l:$PORT,crlf SYSTEM:\"read; read; $ECHO \\\"HTTP/1.0 200 OK\n\\\"; cat\""
-CMD2="$TRACE $SOCAT $opts tcp4-l:$PORT,reuseaddr,crlf exec:\"/bin/bash proxyecho.sh\""
+CMD2="$TRACE $SOCAT $opts tcp4-l:$PORT,reuseaddr,crlf exec:\"bash proxyecho.sh\""
 CMD="$TRACE $SOCAT $opts - proxy:$LOCALHOST:127.0.0.1:1000,pf=ip4,proxyport=$PORT"
 printf "test $F_n $TEST... " $N
 eval "$CMD2 2>\"${te}2\" &"
@@ -4594,7 +4594,7 @@ te="$td/test$N.stderr"
 tdiff="$td/test$N.diff"
 da="test$N $(date) $RANDOM"; da="$da$($ECHO '\r')"
 #CMD2="$TRACE $SOCAT $opts tcp6-l:$PORT,crlf SYSTEM:\"read; read; $ECHO \\\"HTTP/1.0 200 OK\n\\\"; cat\""
-CMD2="$TRACE $SOCAT $opts tcp6-l:$PORT,reuseaddr,crlf exec:\"/bin/bash proxyecho.sh\""
+CMD2="$TRACE $SOCAT $opts tcp6-l:$PORT,reuseaddr,crlf exec:\"bash proxyecho.sh\""
 CMD="$TRACE $SOCAT $opts - proxy:$LOCALHOST6:127.0.0.1:1000,proxyport=$PORT"
 printf "test $F_n $TEST... " $N
 eval "$CMD2 2>\"${te}2\" &"
@@ -4828,7 +4828,7 @@ te="$td/test$N.stderr"
 tdiff="$td/test$N.diff"
 da="test$N $(date) $RANDOM"; da="$da$($ECHO '\r')"
 #CMD2="$TRACE $SOCAT $opts tcp-l:$PORT,crlf SYSTEM:\"read; read; $ECHO \\\"HTTP/1.0 200 OK\n\\\"; cat\""
-CMD2="$TRACE $SOCAT $opts tcp4-l:$PORT,reuseaddr,crlf exec:\"/bin/bash proxyecho.sh -w 2\""
+CMD2="$TRACE $SOCAT $opts tcp4-l:$PORT,reuseaddr,crlf exec:\"bash proxyecho.sh -w 2\""
 CMD="$TRACE $SOCAT $opts - proxy:$LOCALHOST:127.0.0.1:1000,pf=ip4,proxyport=$PORT"
 printf "test $F_n $TEST... " $N
 eval "$CMD2 2>\"${te}1\" &"
@@ -6335,7 +6335,7 @@ $PRINTF "test $F_n $TEST... " $N
 #$TRACE $SOCAT $opts echo SYSTEM:'exec /bin/bash -c "echo \$PPID '">$tpp"'; echo \$$ '">$tp; read x\"",nofork 2>"$te"; stat=$?
 tsh="$td/test$N.sh"
 cat <<EOF >"$tsh"
-#! /bin/bash
+#! /usr/bin/env bash
 echo \$PPID >"$tpp"
 echo \$\$ >"$tp"
 read x
