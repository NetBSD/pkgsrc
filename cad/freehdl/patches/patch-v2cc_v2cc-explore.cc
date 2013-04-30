$NetBSD: patch-v2cc_v2cc-explore.cc,v 1.1 2013/04/30 22:13:57 joerg Exp $

--- v2cc/v2cc-explore.cc.orig	2013-04-30 20:29:08.000000000 +0000
+++ v2cc/v2cc-explore.cc
@@ -2799,7 +2799,7 @@ check_association(pIIR_AssociationList a
 	  // Add entries
 	  association_map [key].push_back (range_vector [j]);
 	  // XXX - why is the cast needed?
-	  association_type_map [key] = (vector<vector<pair<pIIR_Type, pIIR_Type > > >::iterator) &association_type_vectors [i];
+	  association_type_map [key] = association_type_vectors.begin()+i;
 	  // Generate a new key
 	  key.push_back (range_vector [j]);
 	}
