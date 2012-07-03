$NetBSD: patch-pim_pim__bsr.hh,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- pim/pim_bsr.hh.orig	2009-01-05 18:31:02.000000000 +0000
+++ pim/pim_bsr.hh
@@ -275,7 +275,7 @@ public:
     bool	i_am_bsr() const;
     bool	is_new_bsr_preferred(const BsrZone& bsr_zone) const;
     bool	is_new_bsr_same_priority(const BsrZone& bsr_zone) const;
-    struct TimeVal randomized_override_interval(const IPvX& my_addr,
+    class TimeVal randomized_override_interval(const IPvX& my_addr,
 					     uint8_t my_priority) const;
     
     bool	is_bsm_forward() const { return (_is_bsm_forward); }
