$NetBSD: patch-pim_pim__mre__track__state.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- pim/pim_mre_track_state.hh.orig	2013-06-13 19:39:59.000000000 +0000
+++ pim/pim_mre_track_state.hh
@@ -638,6 +638,10 @@ public:
 	return ((output_state() == action.output_state())
 		&& (entry_type() == action.entry_type()));
     }
+    bool operator!=(const PimMreAction& action) const {
+	return ((output_state() != action.output_state())
+		|| (entry_type() != action.entry_type()));
+    }
     
     void perform_action(PimMre& pim_mre, uint32_t vif_index,
 			const IPvX& addr_arg);
