$NetBSD: patch-contrib_olsr_policy__varrw.hh,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- contrib/olsr/policy_varrw.hh.orig	2012-07-03 16:36:15.000000000 +0000
+++ contrib/olsr/policy_varrw.hh
@@ -45,7 +45,7 @@ class OlsrVarRW : public SingleVarRW {
     };
 
     OlsrVarRW(IPv4Net& network, IPv4& nexthop, uint32_t& metric,
-	      IPv4& originator, IPv4& main_addr, uint32_t vtype,
+	      IPv4& originator, IPv4& main_addr, uint32_t &vtype,
 	      PolicyTags& policytags);
 
     // SingleVarRW inteface:
