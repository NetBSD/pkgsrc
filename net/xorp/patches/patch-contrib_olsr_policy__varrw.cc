$NetBSD: patch-contrib_olsr_policy__varrw.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- contrib/olsr/policy_varrw.cc.orig	2012-07-03 16:35:19.000000000 +0000
+++ contrib/olsr/policy_varrw.cc
@@ -39,7 +39,7 @@
 #include "policy_varrw.hh"
 
 OlsrVarRW::OlsrVarRW(IPv4Net& network, IPv4& nexthop, uint32_t& metric,
-		     IPv4& originator, IPv4& main_addr, uint32_t vtype,
+		     IPv4& originator, IPv4& main_addr, uint32_t &vtype,
 		     PolicyTags& policytags)
     : _network(network), _nexthop(nexthop), _metric(metric),
       _originator(originator), _main_addr(main_addr), _vtype(vtype),
