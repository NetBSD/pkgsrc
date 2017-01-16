$NetBSD: patch-signer_src_signer_rrset.c,v 1.1 2017/01/16 09:21:13 he Exp $

Fix for OPENDNSSEC-778: Double NSEEC3PARAM record after re-salt.

--- signer/src/signer/rrset.c.orig	2016-10-17 12:32:58.000000000 +0000
+++ signer/src/signer/rrset.c
@@ -360,8 +360,7 @@ rrset_diff(rrset_type* rrset, unsigned i
                 del_sigs = 1;
             }
             rrset->rrs[i].exists = 1;
-            if ((rrset->rrtype == LDNS_RR_TYPE_DNSKEY ||
-                 rrset->rrtype == LDNS_RR_TYPE_NSEC3PARAMS) && more_coming) {
+            if ((rrset->rrtype == LDNS_RR_TYPE_DNSKEY) && more_coming) {
                 continue;
             }
             rrset->rrs[i].is_added = 0;
