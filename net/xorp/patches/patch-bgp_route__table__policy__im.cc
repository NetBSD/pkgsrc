$NetBSD: patch-bgp_route__table__policy__im.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- bgp/route_table_policy_im.cc.orig	2009-01-05 18:30:43.000000000 +0000
+++ bgp/route_table_policy_im.cc
@@ -122,8 +122,8 @@ PolicyTableImport<A>::route_dump(Interna
     // we want current filter
     rtmsg.route()->set_policyfilter(0, RefPf());
 
-    bool old_accepted = do_filtering(*old_rtmsg, false);
-    bool new_accepted = do_filtering(rtmsg, false);
+    bool old_accepted = this->do_filtering(*old_rtmsg, false);
+    bool new_accepted = this->do_filtering(rtmsg, false);
 
     InternalMessage<A> *new_rtmsg = 0;
     SubnetRoute<A>* copy_new_route = 0;
