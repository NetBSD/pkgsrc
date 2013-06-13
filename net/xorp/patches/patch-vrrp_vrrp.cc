$NetBSD: patch-vrrp_vrrp.cc,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- vrrp/vrrp.cc.orig	2013-06-13 19:45:44.000000000 +0000
+++ vrrp/vrrp.cc
@@ -36,7 +36,7 @@ namespace {
 
 template <class T>
 void
-out_of_range(const string& msg, const T& x)
+my_out_of_range(const string& msg, const T& x)
 {
     ostringstream oss;
 
@@ -64,7 +64,7 @@ Vrrp::Vrrp(VrrpInterface& vif, EventLoop
       _arpd(_vif)
 {
     if (_vrid < 1 || _vrid > 255)
-	out_of_range("VRID out of range", _vrid);
+	my_out_of_range("VRID out of range", _vrid);
 
     char tmp[sizeof "ff:ff:ff:ff:ff:ff"];
     snprintf(tmp, sizeof(tmp), "00:00:5E:00:01:%X", (uint8_t) vrid);
@@ -90,7 +90,7 @@ void
 Vrrp::set_priority(uint32_t priority)
 {
     if (priority == PRIORITY_LEAVE || priority >= PRIORITY_OWN)
-	out_of_range("priority out of range", priority);
+	my_out_of_range("priority out of range", priority);
 
     _priority = priority;
 
