$NetBSD: patch-algo_dominators.ml,v 1.1 2016/06/19 10:36:59 jaapb Exp $

This detection does not work correctly, so short-cut the process
--- algo/dominators.ml.orig	2016-06-15 10:23:22.000000000 +0000
+++ algo/dominators.ml
@@ -101,11 +101,7 @@ let dominators_tarjan graph =
   ) graph;
 
   Util.Timer.start tjntimer;
-#if OCAMLGRAPHVERSION <= 186
   let module Dom = Dominator.Make_graph(G) in
-#else
-  let module Dom = Dominator.Make(G) in
-#endif
   let idom = Dom.compute_all graph start_pkg in
   let domgr = idom.Dom.dom_graph () in
   Util.Timer.stop tjntimer ();
