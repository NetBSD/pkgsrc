$NetBSD: patch-libxipc_xrl__router.hh,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- libxipc/xrl_router.hh.orig	2009-01-05 18:30:56.000000000 +0000
+++ libxipc/xrl_router.hh
@@ -40,8 +40,8 @@ class DispatchState;
 class FinderClient;
 class FinderClientXrlTarget;
 class FinderTcpAutoConnector;
-class FinderDBEntry;
-class XrlRouterDispatchState;
+struct FinderDBEntry;
+struct XrlRouterDispatchState;
 
 class XrlRouter :
     public XrlDispatcher,
