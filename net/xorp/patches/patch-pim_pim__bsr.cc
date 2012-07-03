$NetBSD: patch-pim_pim__bsr.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- pim/pim_bsr.cc.orig	2009-01-05 18:31:02.000000000 +0000
+++ pim/pim_bsr.cc
@@ -2221,7 +2221,7 @@ BsrZone::is_new_bsr_same_priority(const 
     return (false);
 }
 
-struct TimeVal
+class TimeVal
 BsrZone::randomized_override_interval(const IPvX& my_addr,
 				      uint8_t my_priority) const
 {
