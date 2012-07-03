$NetBSD: patch-bgp_route__table__ribin.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- bgp/route_table_ribin.cc.orig	2009-01-05 18:30:43.000000000 +0000
+++ bgp/route_table_ribin.cc
@@ -173,7 +173,7 @@ RibInTable<A>::add_route(const IPNet<A>&
 	// Store it locally.  The BgpTrie will copy it into a ChainedSubnetRoute
 	SubnetRoute<A>* tmp_route = new SubnetRoute<A>(net, pa_list, NULL);
 	tmp_route->set_policytags(policy_tags);
-	A nexthop = fpa_list->nexthop_att()->nexthop();
+	fpa_list->nexthop_att()->nexthop();
 	typename BgpTrie<A>::iterator iter =
 	    _route_table->insert(net, *tmp_route);
 	tmp_route->unref();
