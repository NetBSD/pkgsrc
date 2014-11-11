$NetBSD: patch-windows_get_iplayer_setup.cgi,v 1.1 2014/11/11 21:49:01 shattered Exp $

test(1) uses = for string comparison.

--- windows/get_iplayer_setup.cgi.orig	2012-06-02 16:37:17.000000000 +0000
+++ windows/get_iplayer_setup.cgi
@@ -32,7 +32,7 @@ case "$QUERY_STRING" in
     ;;
 esac
 
-if [ "$TARGET" == "" ]; then
+if [ "$TARGET" = "" ]; then
     cat <<EOF
 Content-Type: text/html
 
