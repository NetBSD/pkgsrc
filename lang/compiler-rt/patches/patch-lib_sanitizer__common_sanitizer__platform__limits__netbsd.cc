$NetBSD: patch-lib_sanitizer__common_sanitizer__platform__limits__netbsd.cc,v 1.1 2018/12/09 20:04:40 adam Exp $

Network ATM has been removed from NetBSD.

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc.orig	2018-10-07 11:20:49.808236967 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc
@@ -116,7 +116,9 @@
 #include <dev/wscons/wsconsio.h>
 #include <dev/wscons/wsdisplay_usl_io.h>
 #include <net/bpf.h>
+#if __NetBSD_Version__ < 899000000
 #include <net/if_atm.h>
+#endif
 #include <net/if_gre.h>
 #include <net/if_ppp.h>
 #include <net/if_pppoe.h>
@@ -132,7 +134,9 @@
 #include <netinet/ip_proxy.h>
 #include <netinet6/in6_var.h>
 #include <netinet6/nd6.h>
+#if __NetBSD_Version__ < 899000000
 #include <netnatm/natm.h>
+#endif
 #include <netsmb/smb_dev.h>
 #include <soundcard.h>
 #include <sys/agpio.h>
@@ -349,8 +353,10 @@ unsigned struct_apm_power_info_sz = size
 unsigned struct_atabusiodetach_args_sz = sizeof(atabusiodetach_args);
 unsigned struct_atabusioscan_args_sz = sizeof(atabusioscan_args);
 unsigned struct_ath_diag_sz = sizeof(ath_diag);
+#if __NetBSD_Version__ < 899000000
 unsigned struct_atm_flowmap_sz = sizeof(atm_flowmap);
 unsigned struct_atm_pseudoioctl_sz = sizeof(atm_pseudoioctl);
+#endif
 unsigned struct_audio_buf_info_sz = sizeof(audio_buf_info);
 unsigned struct_audio_device_sz = sizeof(audio_device);
 unsigned struct_audio_encoding_sz = sizeof(audio_encoding);
@@ -596,7 +602,9 @@ unsigned struct_priq_delete_filter_sz = 
 unsigned struct_priq_interface_sz = sizeof(priq_interface);
 unsigned struct_priq_modify_class_sz = sizeof(priq_modify_class);
 unsigned struct_ptmget_sz = sizeof(ptmget);
+#if __NetBSD_Version__ < 899000000
 unsigned struct_pvctxreq_sz = sizeof(pvctxreq);
+#endif
 unsigned struct_radio_info_sz = sizeof(radio_info);
 unsigned struct_red_conf_sz = sizeof(red_conf);
 unsigned struct_red_interface_sz = sizeof(red_interface);
@@ -1414,6 +1422,7 @@ unsigned IOCTL_BIOCSRTIMEOUT = BIOCSRTIM
 unsigned IOCTL_BIOCGRTIMEOUT = BIOCGRTIMEOUT;
 unsigned IOCTL_BIOCGFEEDBACK = BIOCGFEEDBACK;
 unsigned IOCTL_BIOCSFEEDBACK = BIOCSFEEDBACK;
+#if __NetBSD_Version__ < 899000000
 unsigned IOCTL_SIOCRAWATM = SIOCRAWATM;
 unsigned IOCTL_SIOCATMENA = SIOCATMENA;
 unsigned IOCTL_SIOCATMDIS = SIOCATMDIS;
@@ -1421,6 +1430,7 @@ unsigned IOCTL_SIOCSPVCTX = SIOCSPVCTX;
 unsigned IOCTL_SIOCGPVCTX = SIOCGPVCTX;
 unsigned IOCTL_SIOCSPVCSIF = SIOCSPVCSIF;
 unsigned IOCTL_SIOCGPVCSIF = SIOCGPVCSIF;
+#endif
 unsigned IOCTL_GRESADDRS = GRESADDRS;
 unsigned IOCTL_GRESADDRD = GRESADDRD;
 unsigned IOCTL_GREGADDRS = GREGADDRS;
@@ -1804,8 +1814,10 @@ unsigned IOCTL_MTIOCSLOCATE = MTIOCSLOCA
 unsigned IOCTL_MTIOCHLOCATE = MTIOCHLOCATE;
 unsigned IOCTL_POWER_EVENT_RECVDICT = POWER_EVENT_RECVDICT;
 unsigned IOCTL_POWER_IOC_GET_TYPE = POWER_IOC_GET_TYPE;
+#if __NetBSD_Version__ < 899000000
 unsigned IOCTL_POWER_IOC_GET_TYPE_WITH_LOSSAGE =
     POWER_IOC_GET_TYPE_WITH_LOSSAGE;
+#endif
 unsigned IOCTL_RIOCGINFO = RIOCGINFO;
 unsigned IOCTL_RIOCSINFO = RIOCSINFO;
 unsigned IOCTL_RIOCSSRCH = RIOCSSRCH;
