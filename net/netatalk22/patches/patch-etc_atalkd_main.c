$NetBSD: patch-etc_atalkd_main.c,v 1.1 2021/09/12 15:52:37 nat Exp $

Set interface address correctly for phase 1 networks on NetBSD.

NB: This is a kludge that should not be required.

--- etc/atalkd/main.c.orig	2017-07-09 11:03:31.000000000 +0000
+++ etc/atalkd/main.c
@@ -1228,8 +1228,14 @@ void bootaddr(struct interface *iface)
     }
 
     if ( iface->i_flags & IFACE_PHASE1 ) {
+#ifndef __NetBSD__
 	setaddr( iface, IFACE_PHASE1, 0,
 		iface->i_caddr.sat_addr.s_node, 0, 0 );
+#else
+       setaddr( iface, IFACE_PHASE1, iface->i_caddr.sat_addr.s_net,
+		iface->i_caddr.sat_addr.s_node,
+		iface->i_rt->rt_firstnet, iface->i_rt->rt_lastnet );
+#endif
 
 	if ( iface->i_flags & IFACE_LOOPBACK ) {
 	    iface->i_flags |= IFACE_CONFIG | IFACE_ADDR;
