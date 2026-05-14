$NetBSD: patch-lib_usrp_mpmd_mpmd__link__if__ctrl__udp.cpp,v 1.6 2026/05/14 13:27:32 adam Exp $

work around namespace pollution in NetBSD-9's <net/if.h> before 1.282

--- lib/usrp/mpmd/mpmd_link_if_ctrl_udp.cpp.orig	2026-04-23 11:39:23.000000000 +0000
+++ lib/usrp/mpmd/mpmd_link_if_ctrl_udp.cpp
@@ -92,7 +92,7 @@ mpmd_link_if_ctrl_udp::udp_link_info_map
             }
         }();
         const std::string link_type = link_info.at("type");
-        const size_t if_mtu         = [&link_info]() {
+        const size_t if_mtu_         = [&link_info]() {
             try {
                 return uhd::cast::from_str<size_t>(link_info.at("mtu"));
             } catch (const uhd::runtime_error&) {
@@ -105,7 +105,7 @@ mpmd_link_if_ctrl_udp::udp_link_info_map
         }();
         result.emplace(link_info.at("ipv4"),
             mpmd_link_if_ctrl_udp::udp_link_info_t{
-                udp_port, link_rate, link_type, if_mtu});
+                udp_port, link_rate, link_type, if_mtu_});
     }
 
     return result;
@@ -359,8 +359,8 @@ mpmd_link_if_ctrl_udp::mpmd_link_if_ctrl
             if (info.link_type == "internal") {
                 UHD_LOG_TRACE("MPMD::XPORT::UDP",
                     "MTU for internal interface " << ip_addr << " is "
-                                                  << std::to_string(info.if_mtu));
-                _mtu = std::min(_mtu, info.if_mtu);
+                                                  << std::to_string(info.if_mtu_));
+                _mtu = std::min(_mtu, info.if_mtu_);
             } else {
                 if (force_mtu) {
                     // If force_mtu is set, we still do a single ping on the discovery
