$NetBSD: patch-lib_usrp_mpmd_mpmd__link__if__ctrl__udp.hpp,v 1.1 2022/03/27 17:03:28 tnn Exp $

work around namespace pollution in NetBSD-9's <net/if.h> before 1.282

--- lib/usrp/mpmd/mpmd_link_if_ctrl_udp.hpp.orig	2021-12-14 18:37:20.000000000 +0000
+++ lib/usrp/mpmd/mpmd_link_if_ctrl_udp.hpp
@@ -27,7 +27,7 @@ public:
         std::string udp_port;
         size_t link_rate;
         std::string link_type;
-        size_t if_mtu;
+        size_t if_mtu_;
     };
 
     using udp_link_info_map = std::map<std::string, udp_link_info_t>;
