$NetBSD: patch-src_plugins_wp_share_coqwp_Zbits.v,v 1.1 2017/09/05 07:30:00 dholland Exp $

Make this work with coq-8.6.

--- src/plugins/wp/share/coqwp/Zbits.v~	2017-06-01 08:02:13.000000000 +0000
+++ src/plugins/wp/share/coqwp/Zbits.v
@@ -1868,7 +1868,7 @@ Local Ltac f_equal_hyp h f k :=
   end.
 
 Local Ltac linear2 :=
-  intros x y; (try split); intro H; (try split);
+  intros x y; (try split); intros H; (try split);
   let k := fresh "k" in
   Zbit_ext k; 
   try (destruct H as [H H0] ; f_equal_hyp H0 Zbit k; generalize H0; clear H0);
@@ -1948,7 +1948,7 @@ Proof.
 Qed.
 
 Local Ltac linear3 :=
-  intros x y z; (try split); intro H; (try split);
+  intros x y z; (try split); intros H; (try split);
   let k := fresh "k" in
   Zbit_ext k; 
   try (destruct H as [H H0] ; f_equal_hyp H0 Zbit k; generalize H0; clear H0);
