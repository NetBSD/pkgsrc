$NetBSD: patch-src_tkgate_tclfuncs.c,v 1.1 2013/03/02 18:29:03 joerg Exp $

--- src/tkgate/tclfuncs.c.orig	2013-03-01 14:52:58.000000000 +0000
+++ src/tkgate/tclfuncs.c
@@ -1525,7 +1525,7 @@ int gat_gotoCPathNet(ClientData _d,Tcl_I
     p = argv[1];
 
   n = GModuleDef_findNet(XGate.es->env,p);
-  if (!n) return;
+  if (!n) return TCL_ERROR;
 
   wn1 = n->driver->nodes;
   wn2 = wn1->out ? wn1->out : wn1->in;
