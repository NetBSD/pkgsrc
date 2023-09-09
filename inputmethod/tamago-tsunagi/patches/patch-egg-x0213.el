$NetBSD: patch-egg-x0213.el,v 1.1 2023/09/09 13:04:29 mef Exp $

make-coding-system is obsolete function,
thanks
https://raw.githubusercontent.com/qbilinux/qbilinux/x86_dev/qbilinux/04_xapps/emacs.txz/tamago_tsunagi/emacs28-make-coding-system.patch
or
FreeBSD ports

diff -ru tamago-tsunagi-5.0.7.1/egg-x0213.el tamago-tsunagi-5.0.7.1/egg-x0213.el
--- tamago-tsunagi-5.0.7.1/egg-x0213.el	2015-02-02 22:22:57.000000000 -0000
+++ ./egg-x0213.el	2023-06-25 19:10:00.093386436 -0000
@@ -102,8 +102,10 @@
               (repeat)))
          (repeat)))))
 
-   (make-coding-system 
-    'fixed-euc-jisx0213 4 ?W "Coding System for fixed EUC Japanese"
-    (cons ccl-decode-fixed-euc-jisx0213 ccl-encode-fixed-euc-jisx0213))))
+   (define-coding-system
+     'fixed-euc-jisx0213 "Coding System for fixed EUC Japanese"
+     :mnemonic ?W :coding-type 'ccl
+     :ccl-decoder ccl-decode-fixed-euc-jisx0213
+     :ccl-encoder ccl-encode-fixed-euc-jisx0213)))
 
 (provide 'egg-x0213)
