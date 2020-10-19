$NetBSD: patch-t_7000-mseq.t,v 1.1 2020/10/19 08:18:47 schmonz Exp $

Apply upstream 4d566a6 to fix tests.

--- t/7000-mseq.t.orig	2020-09-12 16:14:35.000000000 +0000
+++ t/7000-mseq.t
@@ -31,7 +31,7 @@ check_test 'whole thread' -eq 4 'mseq 6=
 check_test  'subthread' -eq 2 'mseq 7_ | wc -l'
 check 'parent' 'mseq 6^ | grep "inbox/cur/5_1:2,"'
 check_test 'range' -eq 3 'mseq 1:3 | wc -l'
-check_same 'multiple mmsg' 'mseq 1 2' 'echo "inbox/cur/1:2,\ninbox/cur/2:2,"'
+check_same 'multiple mmsg' 'mseq 1 2' 'printf "inbox/cur/1:2,\ninbox/cur/2:2,\n"'
 
 cat <<! >seq
 inbox/cur/1:2,
