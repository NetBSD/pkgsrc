$NetBSD: patch-tests_test-https.t,v 1.1 2019/03/19 12:12:22 wiz Exp $

Fix test failure on NetBSD. From
https://mercurial-scm.org/repo/hg/rev/406519302520

--- tests/test-https.t.orig	2019-02-01 18:44:06.000000000 +0000
+++ tests/test-https.t
@@ -624,7 +624,7 @@ without client certificate:
 
   $ P="$CERTSDIR" hg id https://localhost:$HGPORT/
   warning: connecting to localhost using legacy security technology (TLS 1.0); see https://mercurial-scm.org/wiki/SecureConnections for more info (?)
-  abort: error: *handshake failure* (glob)
+  abort: error: .*(\$ECONNRESET\$|certificate required|handshake failure).* (re)
   [255]
 
 with client certificate:
