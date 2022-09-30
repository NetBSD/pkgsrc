$NetBSD: patch-lib_usrp_mpmd_mpmd__link__if__ctrl__udp.cpp,v 1.2 2022/09/30 18:12:44 adam Exp $

--- lib/usrp/mpmd/mpmd_link_if_ctrl_udp.cpp.orig	2022-09-14 14:19:33.000000000 +0000
+++ lib/usrp/mpmd/mpmd_link_if_ctrl_udp.cpp
@@ -78,10 +78,10 @@ mpmd_link_if_ctrl_udp::udp_link_info_map
                                      ? std::stoul(link_info.at("link_rate"))
                                      : MAX_RATE_1GIGE;
         const std::string link_type = link_info.at("type");
-        const size_t if_mtu         = std::stoul(link_info.at("mtu"));
+        const size_t if_mtu_        = std::stoul(link_info.at("mtu"));
         result.emplace(link_info.at("ipv4"),
             mpmd_link_if_ctrl_udp::udp_link_info_t{
-                udp_port, link_rate, link_type, if_mtu});
+                udp_port, link_rate, link_type, if_mtu_});
     }
 
     return result;
@@ -316,8 +316,8 @@ mpmd_link_if_ctrl_udp::mpmd_link_if_ctrl
             if (info.link_type == "internal") {
                 UHD_LOG_TRACE("MPMD::XPORT::UDP",
                     "MTU for internal interface " << ip_addr << " is "
-                                                  << std::to_string(info.if_mtu));
-                _mtu = std::min(_mtu, info.if_mtu);
+                                                  << std::to_string(info.if_mtu_));
+                _mtu = std::min(_mtu, info.if_mtu_);
             } else {
                 _mtu = std::min(_mtu, discover_mtu_for_ip(ip_addr,
                                     info.link_rate == MAX_RATE_1GIGE ?
